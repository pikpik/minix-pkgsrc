# $NetBSD: options.mk,v 1.2 2008/02/22 17:04:34 jlam Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.hunspell
PKG_SUPPORTED_OPTIONS=		wide-curses
PKG_SUGGESTED_OPTIONS=		# empty
PKG_LEGACY_OPTS+=		ncursesw:wide-curses

.include "../../mk/bsd.options.mk"

USE_NCURSES=	yes

###
### Wide curses support; otherwise, default to using narrow curses.
###
.if !empty(MACHINE_PLATFORM:MNetBSD-[5-9].*-*)
   CONFIGURE_ENV+=	ac_cv_lib_curses_tparm=yes
.  include "../../mk/curses.buildlink3.mk"
.else
.  if !empty(PKG_OPTIONS:Mwide-curses)
.    include "../../devel/ncursesw/buildlink3.mk"
.  else
.    include "../../devel/ncurses/buildlink3.mk"
.  endif
.endif
