# $NetBSD: Makefile,v 1.26 2007/02/02 17:34:18 joerg Exp $

DISTNAME=		KnightCap-3.6
PKGNAME=		knightcap-3.6
PKGREVISION=		4
CATEGORIES=		games
MASTER_SITES=		ftp://samba.anu.edu.au/pub/KnightCap/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://anu.samba.org/KnightCap/
COMMENT=		Chess engine with 3D OpenGL-rendered chessboard

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_TARGET=		KnightCap

WRKSRC=			${WRKDIR}/Export

MAKE_ENV+=		MESA=${BUILDLINK_PREFIX.MesaLib}
MAKE_ENV+=		DEFINES=${DEFINES:Q}

DEFINES=		-DTB_DIR=\"${TBDIR:Q}\"

TBDIR=			${PREFIX}/share/egtb
INSTALLATION_DIRS=	bin share/doc/knightcap

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/KnightCap ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/knightcap

.include "../../graphics/Mesa/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
