# $NetBSD$

.include "../../www/php4/Makefile.module"

MODNAME=		pgsql
CATEGORIES+=		databases

DEPENDS+=		postgresql>=6.5.3:../../databases/postgresql

EVAL_PREFIX+=		PGSQLDIR=postgresql
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${PGSQLDIR}

.include "../../mk/bsd.pkg.mk"
