# $NetBSD: options.mk,v 1.1 2006/04/21 09:28:47 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.normalize
PKG_SUPPORTED_OPTIONS=	xmms

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		xmms

.if !empty(PKG_OPTIONS:Mxmms)
PLIST.xmms=		yes
.include "../../audio/xmms/buildlink3.mk"
.endif
