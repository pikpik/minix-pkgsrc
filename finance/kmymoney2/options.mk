# $NetBSD: options.mk,v 1.1 2006/02/09 21:46:47 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.kmymoney2
PKG_SUPPORTED_OPTIONS=	libofx
PKG_SUGGESTED_OPTIONS=	libofx

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		libofx

.if !empty(PKG_OPTIONS:Mlibofx)
.include "../../finance/libofx/buildlink3.mk"
PLIST.libofx=		yes
.endif
