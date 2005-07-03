# $NetBSD: options.mk,v 1.2 2005/05/31 10:01:39 dillo Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.stunnel
PKG_SUPPORTED_OPTIONS=	inet6
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

###
### Support IPv6
###
.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif
