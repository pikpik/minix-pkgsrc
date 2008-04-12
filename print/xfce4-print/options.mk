# $NetBSD: options.mk,v 1.4 2007/04/14 22:13:38 dillo Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xfce4-print
PKG_SUPPORTED_OPTIONS=	cups

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		cups
.if !empty(PKG_OPTIONS:Mcups)
.include "../../print/cups/buildlink3.mk"
PLIST.cups=		yes
.else
CONFIGURE_ARGS+=	--disable-cups
.endif
