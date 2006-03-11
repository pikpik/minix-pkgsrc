# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.zsh
PKG_SUPPORTED_OPTIONS=	zsh-multibyte
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mzsh-multibyte)
CONFIGURE_ARGS+=	--enable-multibyte
.endif
