# $NetBSD$

DISTNAME=	alevt-1.6.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SUNSITE:=apps/video/}

MAINTAINER=	magick@bundy.zhadum.de
HOMEPAGE=	http://user.exit.de/froese/

DEPENDS+=	png>=1.0.6:../../graphics/png
DEPENDS+=	fxtv:../../graphics/fxtv

ONLY_FOR_PLATFORM=	NetBSD-1.4[Y-Z]-* NetBSD-1.4Z[A-Z]-* \
			NetBSD-1.5_ALPHA-* NetBSD-1.[5-9]*-*

USE_X11BASE=	YES
USE_GMAKE=	YES

pre-install:
	${MKDIR} ${PREFIX}/share/pixmaps

.include "../../mk/bsd.pkg.mk"
