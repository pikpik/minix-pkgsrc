# $NetBSD: options.mk,v 1.1 2004/11/14 16:48:55 jmmv Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gmime
PKG_SUPPORTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif
