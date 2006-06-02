# $NetBSD: Makefile,v 1.8 2006/02/05 23:11:28 joerg Exp $

MODNAME=		curl
CATEGORIES+=		www
COMMENT=		PHP extension for curl functions

CONFLICTS=	php-curl-[0-9]

CONFIGURE_ARGS+=	--with-curl=shared,${BUILDLINK_PREFIX.curl}

.include "../../lang/php/ext.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
