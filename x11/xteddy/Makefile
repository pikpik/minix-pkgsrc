# $NetBSD: Makefile,v 1.2 2000/05/31 00:28:56 itohy Exp $

DISTNAME=	xteddy-1.1
CATEGORIES=	x11 games
MASTER_SITES=	http://www.ITN.LiU.SE/~stegu/xteddy/

MAINTAINER=	johnam@mail.kemper.org
HOMEPAGE=	http://www.ITN.LiU.SE/~stegu/xteddy

USE_X11=	YES
USE_XPM=	YES
GNU_CONFIGURE=	YES

pre-install:
	${MKDIR} ${PREFIX}/share/xteddy
	${MKDIR} ${PREFIX}/share/xteddy/pixmaps

.include "../../mk/bsd.pkg.mk"
