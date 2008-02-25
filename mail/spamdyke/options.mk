# $NetBSD: options.mk,v 1.1 2007/05/30 05:58:10 schmonz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.spamdyke
PKG_SUPPORTED_OPTIONS=	tls

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtls)
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-tls
.else
CONFIGURE_ARGS+=	--disable-tls
.endif
