# $NetBSD: Makefile,v 1.17 2004/03/08 20:27:15 minskim Exp $
#

DISTNAME=	rfstool-0.14-source
PKGNAME=	rfstool-0.14
CATEGORIES=	sysutils
MASTER_SITES=	http://p-nand-q.com/download/rfstool/
EXTRACT_SUFX=	.zip

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://p-nand-q.com/download/rfstool/overview.html
COMMENT=	Tools to access ReiserFS partitions

WRKSRC=		${WRKDIR}/${PKGNAME}/rfstool
MAKEFILE=	makefile.gcc3x
USE_LANGUAGES+=	c++

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rfstool ${PREFIX}/sbin/rfstool

.include "../../mk/bsd.pkg.mk"
