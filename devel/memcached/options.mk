# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.memcached

PKG_SUPPORTED_OPTIONS=	dtrace
PKG_SUGGESTED_OPTIONS=	# empty

.include "../../mk/bsd.options.mk"

###
### Enable Dtrace support
###
.if !empty(PKG_OPTIONS:Mdtrace)
CONFIGURE_ARGS+=	--enable-dtrace
.endif
