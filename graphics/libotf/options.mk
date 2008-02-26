# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.libotf
PKG_SUPPORTED_OPTIONS=	x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx11)
.include "../../mk/xaw.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-x
.endif
