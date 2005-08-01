# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.libmilter812
# just needed for Makefile.common to work
PKG_SUPPORTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

###
### IPv6 support.
###
.if !empty(PKG_OPTIONS:Minet6)
.endif
