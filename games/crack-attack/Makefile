# $NetBSD: Makefile,v 1.1.1.1 2003/12/03 23:08:56 xtraeme Exp $
#

DISTNAME=	crack-attack-1.1.10
CATEGORIES=	games
MASTER_SITES=	http://aluminumangel.org/cgi-bin/download_counter.cgi?attack_linux+attack/

MAINTAINER=	snj@pobox.com
HOMEPAGE=	http://aluminumangel.org/attack/
COMMENT=	Tetris Attack inspired game

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES
USE_LANGUAGES=	c c++
USE_X11=	YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${PREFIX}/share/doc/html/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/doc/*.jpg ${PREFIX}/share/doc/html/${PKGBASE}

.include "../../graphics/Mesa/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
