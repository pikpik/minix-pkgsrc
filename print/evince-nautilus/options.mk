# $NetBSD: options.mk,v 1.1 2008/10/25 00:11:13 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.evince
PKG_SUPPORTED_OPTIONS=	dvi djvu
PKG_SUGGESTED_OPTIONS=	# none

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdvi)
CONFIGURE_ARGS+=	--enable-dvi
#BUILD_DIRS=		pdf dvi backend lib properties
.include "../../print/kpathsea/buildlink3.mk"
#.else
#BUILD_DIRS=		pdf backend lib properties
.endif

.if !empty(PKG_OPTIONS:Mdjvu)
CONFIGURE_ARGS+=	--enable-djvu
.include	"../../graphics/djvulibre-lib/buildlink3.mk"
.endif
