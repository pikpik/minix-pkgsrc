# $NetBSD: Makefile,v 1.12 2003/09/18 16:25:13 jmmv Exp $
#

.include "../../devel/libtool/Makefile.common"

PKGNAME=	${DISTNAME:C/-/-info-/}
SVR4_PKGNAME=	ltooi

COMMENT=	Generic shared library support script - info pages

CONFLICTS+=	libtool<1.3.5nb11

USE_MAKEINFO=	YES
INFO_FILES=	libtool.info

do-build:
	cd ${WRKSRC}/doc ; ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM}

do-install:
	cd ${WRKSRC}/doc ; ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} install

.include "../../mk/bsd.pkg.mk"
