# $NetBSD: Makefile,v 1.22 2002/06/06 11:25:52 manu Exp $

.include "Makefile.common"

PKGREVISION=	1

CONFIGURE_ARGS+=	--disable-gnome
CONFIGURE_ARGS+=	--disable-zvt

CONFLICTS+=		xchat-gnome-[0-9]*

.include "../../graphics/gdk-pixbuf/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
