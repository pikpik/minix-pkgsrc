# $NetBSD: Makefile,v 1.1.1.1 2006/07/22 19:43:29 abs Exp $

DISTNAME=	tomcat-connectors-${JK_VERSION}-src
PKGNAME=	ap2-jk-${JK_VERSION}

MAKE_PARAMS+=		USE_APXS=1
MAKE_PARAMS+=		WITH_APXS=${APXS}

.include "../../www/ap-jk/Makefile.common"
.include "../../www/apache2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
