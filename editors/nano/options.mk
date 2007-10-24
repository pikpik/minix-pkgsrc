# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.nano
PKG_SUPPORTED_OPTIONS=	ncursesw

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mncursesw)
.  include "../../devel/ncursesw/buildlink3.mk"
.else
.  include "../../mk/curses.buildlink3.mk"
.endif
