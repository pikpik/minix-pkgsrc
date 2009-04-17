# $NetBSD: options.mk,v 1.2 2009/03/07 15:02:23 seb Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.x2vnc

PKG_SUPPORTED_OPTIONS=	dga
PKG_SUGGESTED_OPTIONS=	dga

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdga)
. include "../../x11/libXxf86dga/buildlink3.mk"
. include "../../x11/xf86dgaproto/buildlink3.mk"
.endif
