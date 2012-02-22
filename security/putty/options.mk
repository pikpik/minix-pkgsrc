# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.putty
PKG_SUPPORTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CFLAGS+=	-DIPV6
.endif
