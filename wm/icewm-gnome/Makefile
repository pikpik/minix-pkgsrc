# $NetBSD: Makefile,v 1.2 2001/02/17 17:21:41 wiz Exp $

PKGNAME=		${DISTNAME:S/-/-gnome-/}
COMMENT=		small, fast and light-weight window manager (GNOME version)

CONFLICTS+=		icewm-[0-9]*

.include "../../wm/icewm/Makefile.common"

CONFIGURE_ARGS+=	--with-gnome-menus="${GNOME_CONFIG}"
CONFIGURE_ARGS+=	--with-imlib

.include "../../x11/gnome-libs/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
