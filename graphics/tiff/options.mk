# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.tiff
PKG_SUPPORTED_OPTIONS=	lzw
PKG_DEFAULT_OPTIONS=	lzw
.include "../../mk/bsd.options.mk"

###
### LZW compression support
###
.if !empty(PKG_OPTIONS:Mlzw)
CONFIGURE_ARGS+=	--enable-lzw
.else
CONFIGURE_ARGS+=	--disable-lzw
.endif
