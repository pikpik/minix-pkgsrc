# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.ocsigen
PKG_SUPPORTED_OPTIONS=	ocamlduce

.include "../../mk/bsd.prefs.mk"

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mocamlduce)
DEPENDS+=		ocamlduce>=3.09.3:../../lang/ocamlduce
CONFIGURE_ARGS+=	--enable-ocamlduce
PLIST_SRC+=		PLIST.ocamlduce
.else
CONFIGURE_ARGS+=	--disable-ocamlduce
.endif
PLIST_SRC+=		PLIST
