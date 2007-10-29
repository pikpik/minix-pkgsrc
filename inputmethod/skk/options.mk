# $NetBSD: options.mk,v 1.3 2006/03/20 05:30:33 jlam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.skk
PKG_SUPPORTED_OPTIONS=	lookup

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlookup)
.include "../../misc/lookup/buildlink3.mk"
PLIST_SUBST+=	FOR_LOOKUP=""
.else
PLIST_SUBST+=	FOR_LOOKUP="@comment "
.endif
