# $NetBSD: options.mk,v 1.2 2005/05/31 10:01:37 dillo Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dbmail
PKG_OPTIONS_REQUIRED_GROUPS=	sql
PKG_OPTIONS_GROUP.sql=	mysql pgsql
PKG_SUGGESTED_OPTIONS=	mysql

.include "../../mk/bsd.options.mk"

###
### MySQL database support
###
.if !empty(PKG_OPTIONS:Mmysql)
.include "../../mk/mysql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-mysql
SQLDB=			mysql
.endif

###
### PostgreSQL database support
###
.if !empty(PKG_OPTIONS:Mpgsql)
.include "../../mk/pgsql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-pgsql
SQLDB=			pgsql
.endif
