# $NetBSD: Makefile,v 1.19 2004/03/08 08:43:33 adam Exp $
#

.include "Makefile.common"

COMMENT=	Game like Boulder Dash, Emerald Mine, or Sokoban (X11 build)

.if ${OPSYS} == "SunOS"
BUILD_TARGET=	solaris
.else
BUILD_TARGET=	x11
.endif
CONFLICTS=	rocksndiamonds-sdl-[1-9]*
