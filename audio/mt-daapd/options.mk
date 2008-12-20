# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.mt-daapd
PKG_SUPPORTED_OPTIONS=	howl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mhowl)
.include "../../net/howl/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-howl
CFLAGS+=		-I${PREFIX}/include/howl
.else
.endif
