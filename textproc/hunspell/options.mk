# $NetBSD: options.mk,v 1.1.1.1 2007/09/11 17:40:29 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.hunspell
PKG_SUPPORTED_OPTIONS=		wide-curses
PKG_SUGGESTED_OPTIONS=		# empty
PKG_LEGACY_OPTS+=		ncursesw:wide-curses

.include "../../mk/bsd.options.mk"

USE_NCURSES=	yes

.if !empty(PKG_OPTIONS:Mwide-curses)
.  include "../../devel/ncursesw/buildlink3.mk"
.else
.  include "../../devel/ncurses/buildlink3.mk"
.endif
