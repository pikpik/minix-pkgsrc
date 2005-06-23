# $NetBSD: Makefile,v 1.14 2005/06/01 18:02:44 jlam Exp $
#

DISTNAME=	libdockapp-0.4.0
PKGREVISION=	1
CATEGORIES=	devel wm
MASTER_SITES=	http://solfertje.student.utwente.nl/~dalroi/libdockapp/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://solfertje.student.utwente.nl/~dalroi/libdockapp/
COMMENT=	Simple library to create dockapps for WindowMaker

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/libdockapp
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/libdockapp

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
