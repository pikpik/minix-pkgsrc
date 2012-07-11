# $NetBSD: options.mk,v 1.1.1.1 2012/01/08 15:18:40 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libcarddav
PKG_SUPPORTED_OPTIONS=	doc
PKG_SUGGESTED_OPTIONS=	doc
PKG_OPTIONS_LEGACY_OPTS+=	doxygen:doc

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	doc

.if !empty(PKG_OPTIONS:Mdoc)
BUILD_DEPENDS+=		doxygen>=1.8.1.1:../../devel/doxygen
BUILD_DEPENDS+=		tex-ec-[0-9]*:../../fonts/tex-ec
BUILD_DEPENDS+=		tex-tocloft-[0-9]*:../../print/tex-tocloft
# only xtab.sty is necessary from following
BUILD_DEPENDS+=		teTeX-texmf-[0-9]*:../../print/teTeX3-texmf
CONFIGURE_ARGS+=	--enable-doc
PLIST.doc=		yes
.else
CONFIGURE_ARGS+=	--disable-doxygen-doc
.endif
