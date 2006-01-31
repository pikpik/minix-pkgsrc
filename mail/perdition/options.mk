# $NetBSD: options.mk,v 1.6 2005/01/08 19:58:16 schmonz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.perdition
PKG_SUPPORTED_OPTIONS=	ssl
PKG_SUGGESTED_OPTIONS=	ssl

.include "../../mk/bsd.options.mk"

###
### Build with OpenSSL as the underlying crypto library.
###
.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif
