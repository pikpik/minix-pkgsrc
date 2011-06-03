# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.unbound
PKG_SUPPORTED_OPTIONS=		libevent
PKG_SUGGESTED_OPTIONS=		libevent

.include "../../mk/bsd.options.mk"

###
### libevent
###
.if !empty(PKG_OPTIONS:Mlibevent)
CONFIGURE_ARGS+=	--with-libevent=${BUILDLINK_PREFIX.libevent}
.include "../../devel/libevent/buildlink3.mk"
.endif
