# $NetBSD: options.mk,v 1.1 2006/09/24 16:28:20 salo Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.epiphany
PKG_SUPPORTED_OPTIONS=	enchant # avahi
PKG_SUGGESTED_OPTIONS=	enchant

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Menchant)
CONFIGURE_ARGS+=	--enable-spell-checker
.include "../../textproc/enchant/buildlink3.mk"
.endif
