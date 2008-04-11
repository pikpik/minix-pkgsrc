# $NetBSD: options.mk,v 1.1 2007/08/23 17:10:39 abs Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.mediatomb

PKG_SUPPORTED_OPTIONS=	javascript

PKG_SUGGESTED_OPTIONS=	javascript

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mjavascript)
.include "../../lang/spidermonkey/buildlink3.mk"
.endif
