# $NetBSD$
#
PKG_OPTIONS_VAR=	PKG_OPTIONS.cheese
PKG_SUPPORTED_OPTIONS=	hal

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mhal)
CONFIGURE_ARGS+=	--enable-hal
# XXX FIXME
#.  include "../../sysutils/hal/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--enable-hal=no
.endif
