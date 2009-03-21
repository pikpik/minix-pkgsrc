# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.vala
PKG_SUPPORTED_OPTIONS+=	vapigen
PKG_SUGGESTED_OPTIONS+=	vapigen

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mvapigen)
CONFIGURE_ARGS+=	--enable-vapigen
PLIST_SRC+=		PLIST PLIST.vapigen
.endif
