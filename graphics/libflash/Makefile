# $NetBSD: Makefile,v 1.2 2001/02/16 15:22:25 wiz Exp $
#

PKGNAME=	lib${DISTNAME}

COMMENT=	open source flash(tm) library

DEPENDS+=	jpeg-6b:../../graphics/jpeg

USE_LIBTOOL=	yes

do-build:
		cd ${WRKSRC}/Lib && ${SETENV} ${MAKE_ENV} ${MAKE}

do-install:
		cd ${WRKSRC}/Lib && ${SETENV} ${MAKE_ENV} ${MAKE} install

.include	"Makefile.common"
