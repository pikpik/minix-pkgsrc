# $NetBSD: Makefile,v 1.38 2006/07/22 19:41:34 abs Exp $

DISTNAME=	tomcat-connectors-${JK_VERSION}-src
PKGNAME=	ap-jk-${JK_VERSION}

MAKE_PARAMS+=		USE_APXS=1
MAKE_PARAMS+=		WITH_APXS=${APXS}

.include "../../www/ap-jk/Makefile.common"
.include "../../www/apache/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
