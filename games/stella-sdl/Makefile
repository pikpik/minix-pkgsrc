# $NetBSD: Makefile,v 1.16 2004/02/01 01:43:29 jlam Exp $

PKGNAME=	stella-sdl-${STELLA_VERSION}
CONFLICTS=	stella-[0-9]*

.include "../stella/Makefile.common"

# SOUND_SDL doesn't work
#MAKE_ENV+=	SOUND_SDL=1
MAKE_ENV+=	SOUND_OSS=1 JOYSTICK_SUPPORT=1
ALL_TARGET=	linux-sdl
STELLA=		stella.sdl

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
