# $NetBSD: Makefile,v 1.1.1.1 2000/12/17 09:21:20 jlam Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		mysql
CATEGORIES+=		databases

DEPENDS+=		mysql-client>=3.22:../../databases/mysql-client

EVAL_PREFIX+=		MYSQLDIR=mysql-client
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${MYSQLDIR}

.include "../../mk/bsd.pkg.mk"
