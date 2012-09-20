# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-gnome2-desktop
PKG_SUPPORTED_OPTIONS=	evolution
PKG_SUGGESTED_OPTIONS=	evolution

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		evolution

.if !empty(PKG_OPTIONS:Mevolution)
PLIST.evolution=	yes
.include "../../mail/evolution-data-server/buildlink3.mk"
.endif
