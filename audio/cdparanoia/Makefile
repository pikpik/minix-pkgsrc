# $NetBSD$

DISTNAME=	cdparanoia-III-alpha9.7
PKGNAME=	cdparanoia-3.a9.7
CATEGORIES=	audio
MASTER_SITES=	http://www.xiph.org/paranoia/download/
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.xiph.org/paranoia/

GNU_CONFIGURE=	YES
ALL_TARGET=	static

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cdparanoia ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cdparanoia.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
