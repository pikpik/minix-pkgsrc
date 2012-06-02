# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnumeric
PKG_SUPPORTED_OPTIONS=	psiconv

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpsiconv)
.include "../../converters/psiconv/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-psiconv
.endif
