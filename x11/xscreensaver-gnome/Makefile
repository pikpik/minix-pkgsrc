# $NetBSD: Makefile,v 1.2 2000/07/10 18:18:39 tron Exp $
#

PKGNAME=	${DISTNAME:S/-/-gnome-/:S/$/nb1/}

DEPENDS+=	control-center>=1.2.0:../../x11/controlcenter

CONFLICTS+=	xscreensaver-[0-9]*

PLIST_SRC=	${.CURDIR}/pkg/PLIST

.include "../../x11/xscreensaver/Makefile.common"
