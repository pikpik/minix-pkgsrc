# $NetBSD: Makefile,v 1.1 2000/06/03 19:07:30 fredb Exp $
#

PKGNAME=	${DISTNAME:S/-/-gnome-/}

DEPENDS+=	gnome-core>=1.2.0:../../x11/gnome-core

CONFLICTS+=	xscreensaver-[0-9]*

PLIST_SRC=	${.CURDIR}/pkg/PLIST

.include "../../x11/xscreensaver/Makefile.common"
