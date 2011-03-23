# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.slrn
PKG_SUPPORTED_OPTIONS=		ssl uulib
PKG_SUGGESTED_OPTIONS=		ssl

.include "../../mk/bsd.options.mk"

###
### SSL support
###
.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE:Q}
.else
CONFIGURE_ARGS+=	--without-ssl
.endif

###
### uulib support
###
.if !empty(PKG_OPTIONS:Muulib)
.  include "../../converters/uulib/buildlink3.mk"
CONFIGURE_ARGS+=	--with-uudeview
.else
CONFIGURE_ARGS+=	--without-uudeview
.endif
