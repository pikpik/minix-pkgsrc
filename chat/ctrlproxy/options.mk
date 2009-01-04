# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.ctrlproxy

PKG_SUPPORTED_OPTIONS=	ssl

.include "../../mk/bsd.options.mk"

###
### Build in SSL support via gnutls
###
.if !empty(PKG_OPTIONS:Mssl)
.include "../../security/gnutls/buildlink3.mk"
.endif
