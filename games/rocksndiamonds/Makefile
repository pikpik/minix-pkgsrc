# $NetBSD: Makefile,v 1.16 2003/09/15 15:20:44 adam Exp $
#

.include "Makefile.common"

COMMENT=	Game like Boulder Dash, Emerald Mine, or Sokoban (X11 build)

.if ${OPSYS} == "SunOS"
ALL_TARGET=	solaris
.elif ${OPSYS} == "Darwin"
ALL_TARGET=	mac
.else
ALL_TARGET=	x11
.endif
CONFLICTS=	rocksndiamonds-sdl-[1-9]*
