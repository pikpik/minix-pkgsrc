# $NetBSD: Makefile,v 1.63 2009/05/26 18:15:20 drochner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.rhythmbox
PKG_SUPPORTED_OPTIONS=	hal
PKG_SUGGESTED_OPTIONS=	hal
PLIST_VARS+=		hal

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mhal)
CONFIGURE_ARGS+=	--with-ipod
.include "../../audio/libgpod/buildlink3.mk"
# needs a newer libmtp
#CONFIGURE_ARGS+=	--with-mtp
#.include "../../devel/libmtp/buildlink3.mk"
CONFIGURE_ARGS+=	--with-hal
PLIST.hal=		yes
.include "../../sysutils/hal/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-hal
.endif
