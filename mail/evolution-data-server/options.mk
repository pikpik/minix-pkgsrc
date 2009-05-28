# $NetBSD: Makefile,v 1.88 2009/05/19 08:59:21 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.evolution-data-server
PKG_SUPPORTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif
