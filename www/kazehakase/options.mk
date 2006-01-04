# $NetBSD$
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.kazehakase
PKG_SUPPORTED_OPTIONS=	gnutls
PKG_SUGGESTED_OPTIONS+=	gnutls

.include "../../www/mozilla/gecko-options.mk"
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnutls)
.  include "../../security/gnutls/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-ssl
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif
