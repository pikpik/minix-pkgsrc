# $NetBSD: options.mk,v 1.5 2009/10/21 17:28:02 drochner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.evince
PKG_SUPPORTED_OPTIONS=	dvi djvu xps

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		${PKG_SUPPORTED_OPTIONS}

.if !empty(PKG_OPTIONS:Mdvi)
PLIST.dvi=		yes
.include "../../print/kpathsea/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-dvi
.endif

.if !empty(PKG_OPTIONS:Mdjvu)
PLIST.djvu=		yes
.include "../../graphics/djvulibre-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-djvu
.endif

.if !empty(PKG_OPTIONS:Mxps)
PLIST.xps=		yes
.include "../../print/libgxps/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-xps
.endif
