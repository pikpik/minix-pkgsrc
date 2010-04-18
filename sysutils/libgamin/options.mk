# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.libgamin
PKG_SUPPORTED_OPTIONS=	debug

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
CONFIGURE_ARGS+=	--enable-debug-api
.endif
