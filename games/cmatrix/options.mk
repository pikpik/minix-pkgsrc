# $NetBSD$

PKG_OPTIONS_VAR=        PKG_OPTIONS.cmatrix
PKG_SUPPORTED_OPTIONS=  ncurses
PKG_SUGGESTED_OPTIONS=  ncurses

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mncurses)
.include "../../devel/ncurses/buildlink3.mk"
.endif
