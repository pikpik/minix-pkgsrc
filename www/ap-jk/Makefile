# $NetBSD: Makefile,v 1.37 2006/06/08 12:15:12 joerg Exp $

DISTNAME=	jakarta-tomcat-connectors-${JK_VERSION}-src
PKGNAME=	ap-jk-${JK_VERSION}
PKGREVISION=	1

MAKE_PARAMS+=		USE_APXS=1
MAKE_PARAMS+=		WITH_APXS=${APXS}

.include "../../www/ap-jk/Makefile.common"
.include "../../www/apache/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
