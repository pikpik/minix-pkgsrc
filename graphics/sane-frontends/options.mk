# $NetBSD: Makefile,v 1.37 2007/10/28 10:58:21 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.sane-frontends
PKG_SUPPORTED_OPTIONS=	gimp
PKG_SUGGESTED_OPTIONS=	gimp

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgimp)
.include "../../graphics/gimp/buildlink3.mk"
.endif
