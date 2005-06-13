# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.poppassd
PKG_SUPPORTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ENV+=		O_DEFS="${O_DEFS}" CFLAGS="-DINET6"
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif
