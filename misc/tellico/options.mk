# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.tellico
PKG_SUPPORTED_OPTIONS=	poppler

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpoppler)
.include "../../print/poppler-qt/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-poppler
.endif
