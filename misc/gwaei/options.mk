# $NetBSD: options.mk,v 1.4 2011/01/25 11:02:35 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gwaei
PKG_SUPPORTED_OPTIONS=	gnome
PKG_SUGGESTED_OPTIONS=	gnome

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnome)
PLIST_SRC+=		PLIST.gnome

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libunique3/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.else
CONFIGURE_ARGS+=	--without-gnome
.endif
