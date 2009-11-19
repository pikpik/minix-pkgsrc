# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.vnstat
PKG_SUPPORTED_OPTIONS=	gd
PKG_SUGGESTED_OPTIONS=	gd

.include "../../mk/bsd.options.mk"

PLIST_VARS=	gd
###
### Add support for image output
###
.if !empty(PKG_OPTIONS:Mgd)
BUILD_TARGET=	all
PLIST.gd=	yes
.include "../../graphics/gd/buildlink3.mk"
.else
BUILD_TARGET=
.endif
