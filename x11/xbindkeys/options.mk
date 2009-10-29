# $NetBSD: options.mk,v 1.1 2007/10/15 14:39:47 abs Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xbindkeys
PKG_SUPPORTED_OPTIONS=	guile
PKG_SUGGESTED_OPTIONS+=	guile

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mguile)
CONFIGURE_ARGS+=	--enable-guile
.include "../../lang/guile/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-guile
.endif
