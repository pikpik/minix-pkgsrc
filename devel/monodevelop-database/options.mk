# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.monodevelop-database
PKG_SUPPORTED_OPTIONS=	mysql
PKG_SUGGESTED_OPTIONS=	mysql

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmysql)
.include "../../databases/csharp-mysql/buildlink3.mk"
.endif
