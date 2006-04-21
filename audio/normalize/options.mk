# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.normalize
PKG_SUPPORTED_OPTIONS=	xmms

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mxmms)
PLIST_SUBST+=	XMMS_PLUGIN=
.include "../../audio/xmms/buildlink3.mk"
.else
PLIST_SUBST+=	XMMS_PLUGIN="@comment "
.endif
