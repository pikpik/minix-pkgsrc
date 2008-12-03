# $NetBSD$
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.celt
PKG_SUPPORTED_OPTIONS=	ogg
PKG_SUGGESTED_OPTIONS=	ogg

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mogg)
CONFIGURE_ARGS+=	--with-ogg=${BUILDLINK_PREFIX.libogg:Q}
.  include "../../multimedia/libogg/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-ogg
.endif
