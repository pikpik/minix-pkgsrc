# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.galeon

.include "../../www/seamonkey/gecko-options.mk"
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mfirefox)
CONFIGURE_ARGS+=	--with-mozilla=firefox
.else
BUILDLINK_RPATHDIRS.seamonkey+=	lib/seamonkey
.endif
