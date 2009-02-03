# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.gegl
PKG_SUPPORTED_OPTIONS=	svg
PKG_SUGGESTED_OPTIONS=	svg

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	svg

.if !empty(PKG_OPTIONS:Msvg)
.include "../../graphics/librsvg/buildlink3.mk"
PLIST.svg=	yes
.endif
