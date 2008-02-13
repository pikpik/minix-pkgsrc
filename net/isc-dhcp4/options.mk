# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.dhcp
PKG_SUPPORTED_OPTIONS+=	inet6

.include "../../mk/bsd.options.mk"

###
### Enable ipv6 support
###
.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-dhcpv6
.else
CONFIGURE_ARGS+=	--disable-dhcpv6
.endif
