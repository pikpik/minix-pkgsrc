# $NetBSD: Makefile,v 1.22 2000/06/01 17:46:15 rh Exp $

PKGNAME=		g${DISTNAME}
CATEGORIES+=		gnome

DEPENDS+=		gnome-core-*:../../x11/gnome-core

USE_X11BASE=		# defined
CONFIGURE_ARGS+=	--with-tm-x-support
CONFIGURE_ARGS+=	--with-gnome

post-install:
	${RMDIR} ${PREFIX}/share/gnome/help/gmc/C/figs

.include "../../sysutils/mc/Makefile.common"
