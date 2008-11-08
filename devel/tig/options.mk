# $NetBSD$
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.tig
PKG_SUPPORTED_OPTIONS=	wide-curses
###
###	Git commit messages often contain UTF-8, so we default
###	to this here.
###
PKG_SUGGESTED_OPTIONS+=	wide-curses

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mwide-curses)
.  include "../../devel/ncursesw/buildlink3.mk"
.else
.  include "../../devel/ncurses/buildlink3.mk"
.endif
