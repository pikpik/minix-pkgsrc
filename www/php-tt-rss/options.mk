# $NetBSD: options.mk,v 1.3 2012/07/10 13:20:19 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.php-tt-rss

PKG_OPTIONS_REQUIRED_GROUPS=	db
PKG_OPTIONS_GROUP.db=		mysql pgsql

PKG_SUGGESTED_OPTIONS=	pgsql

.include "../../mk/bsd.options.mk"

###
### Use mysql or pgsql backend
###
.if !empty(PKG_OPTIONS:Mmysql)
DEPENDS+=	${PHP_PKG_PREFIX}-mysql>=5.2.0:../../databases/php-mysql
.elif !empty(PKG_OPTIONS:Mpgsql)
DEPENDS+=	${PHP_PKG_PREFIX}-pgsql>=5.2.0:../../databases/php-pgsql
.endif
