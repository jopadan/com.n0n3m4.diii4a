/* Thread functions */

#include <assert.h>

#ifdef Q3E_THREAD_INC
#error "q3e_thread.inc included many times!"
#endif
#define Q3E_THREAD_INC

#ifdef Q3E_REQUIRE_THREAD

#define ENTER_CRITICAL_SECTION() (Q3E_Sys_EnterCriticalSection(Q3E_MAX_LOCAL_CRITICAL_SECTIONS - 1));
#define LEAVE_CRITICAL_SECTION() (Q3E_Sys_LeaveCriticalSection(Q3E_MAX_LOCAL_CRITICAL_SECTIONS - 1));

#define ENTER_WINDOW_CHANGED_CRITICAL_SECTION (Q3E_Sys_EnterCriticalSection(CRITICAL_SECTION_SYS));
#define LEAVE_WINDOW_CHANGED_CRITICAL_SECTION (Q3E_Sys_LeaveCriticalSection(CRITICAL_SECTION_SYS));

// we use an extra lock for the local stuff
const int Q3E_MAX_CRITICAL_SECTIONS		= 1;
#define Q3E_MAX_LOCAL_CRITICAL_SECTIONS 2
static pthread_mutex_t q3e_global_lock[ Q3E_MAX_LOCAL_CRITICAL_SECTIONS ];

enum {
    CRITICAL_SECTION_SYS,
    CRITICAL_SECTION_INTERNAL, // internal used
};

#define Q3E_MAX_TRIGGER_EVENTS 3
enum {
	TRIGGER_EVENT_CONTEXT_CREATED, // doom3 thread/render thread -> Android SurfaceView thread: notify OpenGL context created
	TRIGGER_EVENT_CONTEXT_DESTROYED, // doom3 thread/render thread -> Android SurfaceView thread: notify OpenGL context destroyed
	TRIGGER_EVENT_WINDOW_CREATED, // Android SurfaceView thread -> doom3/renderer thread: notify native window is created
};

/*
==================
Q3E_Sys_EnterCriticalSection
==================
*/
void Q3E_Sys_EnterCriticalSection(int index)
{
    assert(index >= 0 && index < Q3E_MAX_LOCAL_CRITICAL_SECTIONS);
    pthread_mutex_lock(&q3e_global_lock[index]);
}

/*
==================
Q3E_Sys_LeaveCriticalSection
==================
*/
void Q3E_Sys_LeaveCriticalSection(int index)
{
    assert(index >= 0 && index < Q3E_MAX_LOCAL_CRITICAL_SECTIONS);
    pthread_mutex_unlock(&q3e_global_lock[index]);
}

static pthread_cond_t	q3e_event_cond[ Q3E_MAX_TRIGGER_EVENTS ];
static Q3Ebool 			q3e_signaled[ Q3E_MAX_TRIGGER_EVENTS ];
static Q3Ebool			q3e_waiting[ Q3E_MAX_TRIGGER_EVENTS ];

/*
==================
Q3E_Sys_WaitForEvent
==================
*/
void Q3E_Sys_WaitForEvent(int index)
{
    assert(index >= 0 && index < Q3E_MAX_TRIGGER_EVENTS);
	ENTER_CRITICAL_SECTION();
    assert(!q3e_waiting[ index ]);	// WaitForEvent from multiple threads? that wouldn't be good

    if (q3e_signaled[ index ]) {
        // emulate windows behaviour: signal has been raised already. clear and keep going
        q3e_signaled[ index ] = Q3E_FALSE;
    } else {
        q3e_waiting[ index ] = Q3E_TRUE;
        pthread_cond_wait(&q3e_event_cond[ index ], &q3e_global_lock[ Q3E_MAX_LOCAL_CRITICAL_SECTIONS - 1 ]);
        q3e_waiting[ index ] = Q3E_FALSE;
    }

	LEAVE_CRITICAL_SECTION();
}

/*
==================
Q3E_Sys_TriggerEvent
==================
*/
void Q3E_Sys_TriggerEvent(int index)
{
    assert(index >= 0 && index < Q3E_MAX_TRIGGER_EVENTS);
	ENTER_CRITICAL_SECTION();

    if (q3e_waiting[ index ]) {
        pthread_cond_signal(&q3e_event_cond[ index ]);
    } else {
        // emulate windows behaviour: if no thread is q3e_waiting, leave the signal on so next wait keeps going
        q3e_signaled[ index ] = Q3E_TRUE;
    }

	LEAVE_CRITICAL_SECTION();
}

/*
==================
Q3E_Sys_InitPThreads
==================
*/
void Q3E_Sys_InitThreads()
{
    int i;
    pthread_mutexattr_t attr;

    // init critical sections
    for (i = 0; i < Q3E_MAX_LOCAL_CRITICAL_SECTIONS; i++) {
        pthread_mutexattr_init(&attr);
        pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK);
        pthread_mutex_init(&q3e_global_lock[i], &attr);
        pthread_mutexattr_destroy(&attr);
    }

    // init event sleep/triggers
    for (i = 0; i < Q3E_MAX_TRIGGER_EVENTS; i++) {
        pthread_cond_init(&q3e_event_cond[ i ], NULL);
        q3e_signaled[i] = Q3E_FALSE;
        q3e_waiting[i] = Q3E_FALSE;
    }
}

#define WAIT_FOR_EVENT(index) Q3E_Sys_WaitForEvent(index)
#define TRIGGER_EVENT(index) Q3E_Sys_TriggerEvent(index)

#define INIT_Q3E_THREADS Q3E_Sys_InitThreads()

#define WAIT_CONTEXT_DESTROYED WAIT_FOR_EVENT(TRIGGER_EVENT_CONTEXT_DESTROYED)
#define TRIGGER_CONTEXT_DESTROYED TRIGGER_EVENT(TRIGGER_EVENT_CONTEXT_DESTROYED)

#define WAIT_WINDOW_CREATED WAIT_FOR_EVENT(TRIGGER_EVENT_WINDOW_CREATED)
#define TRIGGER_WINDOW_CREATED TRIGGER_EVENT(TRIGGER_EVENT_WINDOW_CREATED)

#define WAIT_CONTEXT_CREATED WAIT_FOR_EVENT(TRIGGER_EVENT_CONTEXT_CREATED)
#define TRIGGER_CONTEXT_CREATED TRIGGER_EVENT(TRIGGER_EVENT_CONTEXT_CREATED)

#endif