# $NetBSD: Makefile,v 1.2 2012/09/11 23:04:34 asau Exp $

DISTNAME=	teapot-2.3.0
CATEGORIES=	math
MASTER_SITES=	http://www.syntax-k.de/projekte/teapot/

MAINTAINER=	hauke@NetBSD.org
HOMEPAGE=	http://www.syntax-k.de/projekte/teapot/
COMMENT=	Curses based spread sheet program
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++
USE_CMAKE=	yes
CMAKE_ARGS+=	-DENABLE_HELP=NO
CMAKE_ARGS+=	-DPKGMANDIR=${PKGMANDIR}

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
