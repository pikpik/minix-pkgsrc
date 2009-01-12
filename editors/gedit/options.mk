# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.esound
PKG_SUPPORTED_OPTIONS=	enchant
#PKG_SUGGESTED_OPTIONS=	enchant

.include "../../mk/bsd.options.mk"

PLIST_VARS=	enchant
.if !empty(PKG_OPTIONS:Menchant)
PLIST.enchant=	yes
.include "../../textproc/enchant/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.else
CONFIGURE_ARGS+=       --disable-spell
.endif
