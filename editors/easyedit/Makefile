# $NetBSD$
#

DISTNAME=	ee-1.4.5a.src
PKGNAME=	easyedit-1.4.5a
CATEGORIES=	editors
MASTER_SITES=	http://mahon.cwx.net/sources/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://mahon.cwx.net/
COMMENT=	Easy to use text editor

WRKSRC=		${WRKDIR}/${PKGNAME}

do-install:
	${CP} ${WRKSRC}/ee ${PREFIX}/bin/easyedit
	${CP} ${WRKSRC}/ee.1 ${PREFIX}/man/man1/easyedit.1

.include "../../mk/bsd.pkg.mk"
