# $NetBSD: Makefile,v 1.2 2006/11/15 11:04:04 abs Exp $

DISTNAME=	tomcat-connectors-${JK_VERSION}-src
PKGNAME=	ap2-jk-${JK_VERSION}

MAKE_PARAMS+=		USE_APXS=1
MAKE_PARAMS+=		WITH_APXS=${APXS}

PKG_APACHE_ACCEPTED=	apache2 apache22

.include "../../www/ap-jk/Makefile.common"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
