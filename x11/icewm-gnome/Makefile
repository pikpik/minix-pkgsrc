# $NetBSD: Makefile,v 1.3 2000/02/20 17:56:18 wiz Exp $

PKGNAME=	${DISTNAME:S/-/-gnome-/}

DEPENDS+=	gnome-libs-*:../../x11/gnome-libs

CONFLICTS+=	icewm-[0-9]*

CONFIGURE_ARGS+=	--with-gnome-menus=${X11BASE}/bin/gnome-config \
			--with-imlib
CONFIGURE_ENV+=		LIBS="-lintl"

.include "../../x11/icewm/Makefile.common"
