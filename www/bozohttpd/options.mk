# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.bozohttpd
PKG_SUPPORTED_OPTIONS=	bozohttpd-do-htpasswd inet6

.include "../../mk/bsd.options.mk"

###
### Support Apache's .htpasswd files.
###
.if !empty(PKG_OPTIONS:Mbozohttpd-do-htpasswd)
CPPFLAGS+=	-DDO_HTPASSWD
.endif

###
### IPv6 support.
###
.if !empty(PKG_OPTIONS:Minet6)
CPPFLAGS+=	-DINET6
.endif
