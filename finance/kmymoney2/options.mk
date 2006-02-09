# $NetBSD: options.mk,v 1.1 2005/06/08 13:20:04 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.kmymoney2
PKG_SUPPORTED_OPTIONS=	libofx
PKG_SUGGESTED_OPTIONS=	libofx

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlibofx)
.include "../../finance/libofx/buildlink3.mk"
PLIST_SUBST+=	HAS_LIBOFX=""
.else
PLIST_SUBST+=	HAS_LIBOFX="@comment "
.endif
