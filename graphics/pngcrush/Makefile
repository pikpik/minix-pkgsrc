# $NetBSD: Makefile,v 1.3 2000/01/13 08:05:01 rh Exp $
#

DISTNAME=	pngcrush-1.3.4
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.xnot.com/pmt/pub/pngcrush/src/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.xnot.com/pmt/pngcrush/

NO_CONFIGURE=	YES

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o pngcrush *.c -lm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pngcrush ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/pngcrush
	${INSTALL_MAN} ${WRKSRC}/README.txt ${PREFIX}/share/pngcrush

.include "../../mk/bsd.pkg.mk"
