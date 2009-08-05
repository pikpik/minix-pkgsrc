# $NetBSD: options.mk,v 1.2 2008/04/12 22:43:04 jlam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.wl
PKG_SUPPORTED_OPTIONS=	w3m
PKG_SUGGESTED_OPTIONS=	w3m

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		w3m

.if !empty(PKG_OPTIONS:Mw3m)
.include "../../www/emacs-w3m-snapshot/buildlink3.mk"
PLIST.w3m=	yes
.endif
