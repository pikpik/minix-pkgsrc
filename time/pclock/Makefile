# $NetBSD: Makefile,v 1.4 2003/07/17 22:55:03 grant Exp $
#

DISTNAME=	pclock_0.13.1.orig
PKGNAME=	${DISTNAME:S/_/-/:S/.orig//}
PKGREVISION=	1
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}.orig
CATEGORIES=	time x11
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/p/pclock/}

MAINTAINER=	salo@NetBSD.org
COMMENT=	Simple analog clock designed for Window Maker

USE_BUILDLINK2=	YES
USE_X11=	YES

MAKE_ENV+=	LN=${LN}

post-install:
		${INSTALL_DATA_DIR} ${PREFIX}/share/pclock
		${INSTALL_DATA} ${WRKSRC}/XPM/* ${PREFIX}/share/pclock/
		${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pclock
		${INSTALL_DATA} ${WRKSRC}/CREDITS ${PREFIX}/share/doc/pclock
		${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/pclock

.include "../../graphics/xpm/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
