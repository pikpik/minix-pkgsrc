# $NetBSD$
#

DISTNAME=	pngcrush-1.2.1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.xnot.com/pmt/pub/pngcrush/src/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.xnot.com/pmt/pngcrush/

NO_CONFIGURE=	YES

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o pngcrush *.c -lm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pngcrush ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
