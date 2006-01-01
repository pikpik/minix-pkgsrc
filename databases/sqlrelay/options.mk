# $NetBSD: options.mk,v 1.2 2005/12/05 23:55:05 rillig Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.sqlrelay
PKG_SUPPORTED_OPTIONS+= mysql pgsql

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmysql)
CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_DIR:Q}
.include "../../mk/mysql.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
CONFIGURE_ARGS+=	--with-postgresql=${BUILDLINK_DIR:Q}
.include "../../mk/pgsql.buildlink3.mk"
.endif
