# $NetBSD: options.mk,v 1.1 2007/08/14 09:30:56 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.vino
PKG_SUPPORTED_OPTIONS+=	avahi inet6
PKG_SUGGESTED_OPTIONS+=	avahi

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mavahi)
CONFIGURE_ARGS+=	--enable-avahi
.include "../../net/avahi/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-avahi
.endif

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif
