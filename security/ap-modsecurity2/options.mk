# $NetBSD: options.mk,v 1.3 2008/10/12 12:50:17 adrianp Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ap-modsecurity2

PKG_SUPPORTED_OPTIONS=	curl

.include "../../mk/bsd.options.mk"

###
### Bring in support for curl
###
.if !empty(PKG_OPTIONS:Mcurl)
.  include "../../www/curl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-curl=${BUILDLINK_PREFIX.curl}
.else
CONFIGURE_ARGS+=	--without-curl
.endif
