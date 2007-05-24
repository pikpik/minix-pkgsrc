# $NetBSD$
#

DISTNAME=	ucpp-1.3
CATEGORIES=	devel
MASTER_SITES=	http://pornin.nerim.net/ucpp/

MAINTAINER=	asmodai@in-nomine.org
HOMEPAGE=	http://pornin.nerim.net/ucpp/
COMMENT=	C preprocessor and lexer

MAN1=		ucpp.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ucpp ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
