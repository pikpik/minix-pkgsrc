# $NetBSD: Makefile,v 1.7 2009/03/18 13:08:07 jmcneill Exp $

PKG_OPTIONS_VAR=        PKG_OPTIONS.ekiga
PKG_SUPPORTED_OPTIONS+= avahi
PKG_SUGGESTED_OPTIONS+= avahi

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mavahi)
.include "../../net/avahi/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-avahi
.endif
