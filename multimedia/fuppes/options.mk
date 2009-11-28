# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.fuppes
PKG_SUPPORTED_OPTIONS=	mysql

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		${PKG_SUPPORTED_OPTIONS}

.if !empty(PKG_OPTIONS:Mmysql)
PLIST.mysql=		yes
CONFIGURE_ARGS+=	--enable-mysql

.include "../../mk/mysql.buildlink3.mk"
.endif
