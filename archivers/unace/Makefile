# $NetBSD: Makefile,v 1.4 2001/09/09 20:36:11 agc Exp $
#

DISTNAME=	unace-1.2b
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SUNSITE:=utils/compress/}

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://www.winace.com/
COMMENT=	Extract, list and test files in ACE archives

USE_BUILDLINK_ONLY=	yes
USE_GMAKE=		yes

ALL_TARGET=	clean unace

post-build:
	false

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unace ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/unace
	${INSTALL_MAN} ${WRKSRC}/readme.txt ${PREFIX}/share/doc/unace

.include "../../mk/bsd.pkg.mk"
