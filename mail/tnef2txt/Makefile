# $NetBSD$
#

DISTNAME=	tnef2txt-1.4
CATEGORIES=	mail
MASTER_SITES=	http://www.fiction.net/blong/programs/tnef2txt/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.fiction.net/blong/programs/
COMMENT=	portable application/ms-tnef parser

ALL_TARGET=	tnef2txt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tnef2txt ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
