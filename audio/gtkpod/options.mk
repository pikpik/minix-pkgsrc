# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.gtkpod
PKG_SUPPORTED_OPTIONS=	faad
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mfaad)
.  include "../../audio/faad2/buildlink3.mk"
.endif
