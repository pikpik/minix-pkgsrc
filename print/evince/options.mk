# $NetBSD: options.mk,v 1.3 2009/02/18 12:39:04 drochner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.evince
PKG_SUPPORTED_OPTIONS=	dvi djvu gnome
PKG_SUGGESTED_OPTIONS=	gnome

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		${PKG_SUPPORTED_OPTIONS}

.if !empty(PKG_OPTIONS:Mdvi)
CONFIGURE_ARGS+=	--enable-dvi
PLIST.dvi=		yes
GCONF_SCHEMAS+=	evince-thumbnailer-dvi.schemas
.include "../../print/kpathsea/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mdjvu)
CONFIGURE_ARGS+=	--enable-djvu
PLIST.djvu=		yes
GCONF_SCHEMAS+=	evince-thumbnailer-djvu.schemas
.include "../../graphics/djvulibre-lib/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgnome)
COMMENT+=		for the GNOME Desktop
.else
COMMENT+=		(GTK version)
CONFIGURE_ARGS+=	--disable-nautilus
.endif

