# $NetBSD: Makefile,v 1.1.1.1 2001/05/30 11:13:18 agc Exp $

DISTNAME=	gnuboy-1.0.3
CATEGORIES=	emulators
MASTER_SITES=	http://gnuboy.unix-fu.org/src/

MAINTAINER=	motor@diku.dk
HOMEPAGE=	http://gnuboy.unix-fu.org/
COMMENT=	gameboy emulator

GNU_CONFIGURE=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gnuboy
	${INSTALL_PROGRAM} ${WRKSRC}/xgnuboy ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/etc/sample.rc \
	   ${WRKSRC}/docs/* ${PREFIX}/share/doc/gnuboy/

.include "../../mk/bsd.pkg.mk"
