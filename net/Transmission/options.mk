# $NetBSD: options.mk,v 1.10 2009/02/16 12:33:16 drochner Exp $

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.Transmission
PKG_SUPPORTED_OPTIONS=	gtk
PKG_SUGGESTED_OPTIONS=	gtk

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk)
. include "../../graphics/hicolor-icon-theme/buildlink3.mk"
. include "../../sysutils/libnotify/buildlink3.mk"
. include "../../x11/gtk2/buildlink3.mk"
. include "../../sysutils/desktop-file-utils/desktopdb.mk"
CONFIGURE_ARGS+=	--with-gtk
USE_DIRS+=		xdg-1.1
PLIST_SRC+=		${PKGDIR}/PLIST.gtk
.else
CONFIGURE_ARGS+=	--without-gtk
pre-configure:
	touch ${WRKSRC}/po/Makefile
.endif
