# $NetBSD: Makefile,v 1.12 1999/04/15 20:39:47 tron Exp $
#

DISTNAME=		transfig.3.2.3
PKGNAME=		transfig-3.2.3
WRKSRC=			${WRKDIR}/${DISTNAME}
CATEGORIES=		graphics print
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=applications/drawing_tools/transfig/}

MAINTAINER=		root@garbled.net

DEPENDS+=		xpm-3.4k:../../graphics/xpm
DEPENDS+=		jpeg-6b:../../graphics/jpeg

USE_IMAKE=		yes

.include "../../mk/bsd.pkg.mk"
