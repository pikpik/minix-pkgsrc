# $NetBSD$
#
# This file should be included by Makefiles for packages that use curses.
# If a system curses isn't available, then add a dependency on ncurses.
#
# If a package genuinely requires ncurses, then it should directly include
# ncurses/buildlink2.mk instead of this file in the package Makefile.

.if !defined(CURSES_BUILDLINK2_MK)
CURSES_BUILDLINK2_MK=	# defined

.  if !exists(/usr/include/curses.h) && \
      !exists(/usr/include/ncurses.h)
.    include "../../devel/ncurses/buildlink2.mk"
.  endif
.endif  # CURSES_BUILDLINK2_MK
