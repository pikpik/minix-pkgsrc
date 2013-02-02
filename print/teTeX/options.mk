# $NetBSD$

PKG_OPTIONS_VAR=        PKG_OPTIONS.teTeX
PKG_SUPPORTED_OPTIONS+= x11
PKG_SUGGESTED_OPTIONS+= x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx11)
DEPENDS+=      xdvik-[0-9]*:../../print/xdvik
.endif
