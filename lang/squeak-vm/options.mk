# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.squeak-vm
PKG_SUPPORTED_OPTIONS=		nas
PKG_SUGGESTED_OPTIONS=		nas

.include "../../mk/bsd.options.mk"

PLIST_VARS=	nas

.if !empty(PKG_OPTIONS:Mnas)
PLIST.nas=	yes
.include "../../audio/nas/buildlink3.mk"
.endif
