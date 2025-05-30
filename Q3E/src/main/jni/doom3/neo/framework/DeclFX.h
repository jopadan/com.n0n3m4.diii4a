/*
===========================================================================

Doom 3 GPL Source Code
Copyright (C) 1999-2011 id Software LLC, a ZeniMax Media company.

This file is part of the Doom 3 GPL Source Code (?Doom 3 Source Code?).

Doom 3 Source Code is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Doom 3 Source Code is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Doom 3 Source Code.  If not, see <http://www.gnu.org/licenses/>.

In addition, the Doom 3 Source Code is also subject to certain additional terms. You should have received a copy of these additional terms immediately following the terms and conditions of the GNU General Public License which accompanied the Doom 3 Source Code.  If not, please request a copy in writing from id Software at the address below.

If you have questions concerning this license or the applicable additional terms, you may contact in writing id Software LLC, c/o ZeniMax Media Inc., Suite 120, Rockville, Maryland 20850 USA.

===========================================================================
*/

#ifndef __DECLFX_H__
#define __DECLFX_H__

/*
===============================================================================

	idDeclFX

===============================================================================
*/

enum {
	FX_LIGHT,
	FX_PARTICLE,
	FX_DECAL,
	FX_MODEL,
	FX_SOUND,
	FX_SHAKE,
	FX_ATTACHLIGHT,
	FX_ATTACHENTITY,
	FX_LAUNCH,
	FX_SHOCKWAVE
#ifdef _HUMANHEAD
		,
	// HUMANHEAD nla - Support for the 'useAxis'
	FX_USEAXIS,
	// HUMANHEAD nla
#endif
};

//
// single fx structure
//
typedef struct {
	int						type;
	int						sibling;

	idStr					data;
	idStr					name;
	idStr					fire;

#ifdef _HUMANHEAD
	// HUMANHEAD nla
	int					useAxis;
	idVec3				dir;
	// HUMANHEAD END
#endif
	float					delay;
	float					duration;
	float					restart;
	float					size;
	float					fadeInTime;
	float					fadeOutTime;
	float					shakeTime;
	float					shakeAmplitude;
	float					shakeDistance;
	float					shakeImpulse;
	float					lightRadius;
	float					rotate;
	float					random1;
	float					random2;

	idVec3					lightColor;
	idVec3					offset;
	idMat3					axis;

	bool					soundStarted;
	bool					shakeStarted;
	bool					shakeFalloff;
	bool					shakeIgnoreMaster;
	bool					bindParticles;
	bool					explicitAxis;
	bool					noshadows;
	bool					particleTrackVelocity;
	bool					trackOrigin;
} idFXSingleAction;

#ifdef _HUMANHEAD
// HUMANHEAD nla
enum fxAxis { AXIS_CURRENT, AXIS_NORMAL, AXIS_BOUNCE, AXIS_INCOMING, AXIS_CUSTOMLOCAL };
// HUMANHEAD END
#endif

//
// grouped fx structures
//
class idDeclFX : public idDecl
{
	public:
		virtual size_t			Size(void) const;
		virtual const char 	*DefaultDefinition(void) const;
#ifdef _RAVEN
		virtual bool			Parse(const char *text, const int textLength, bool noCaching = false);
#else
		virtual bool			Parse(const char *text, const int textLength);
#endif
		virtual void			FreeData(void);
		virtual void			Print(void) const;
		virtual void			List(void) const;

		idList<idFXSingleAction>events;
		idStr					joint;

	private:
		void					ParseSingleFXAction(idLexer &src, idFXSingleAction &FXAction);
#ifdef _HUMANHEAD
        // HUMANHEAD nla
        void                    ParseUseAxis(idStr& text, idFXSingleAction& action) const;
        // HUMANHEAD END
#endif
};

#endif /* !__DECLFX_H__ */
