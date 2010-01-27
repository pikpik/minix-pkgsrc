# $NetBSD: Makefile,v 1.23 2010/01/18 09:58:57 wiz Exp $

PKG_OPTIONS_VAR= PKG_OPTIONS.comix
PKG_SUPPORTED_OPTIONS= gnome
PKG_SUGGESTED_OPTIONS= gnome

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnome)
.include "../../devel/GConf/buildlink3.mk"
.endif
