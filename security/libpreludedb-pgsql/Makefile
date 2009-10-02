# $NetBSD: Makefile,v 1.26 2009/08/24 13:50:03 hasso Exp $
#

.include "../../security/libpreludedb/Makefile.common"
.include "../../mk/bsd.prefs.mk"

PATCHDIR=		${.CURDIR}/../libpreludedb/patches
PKGNAME=		libpreludedb-pgsql-${VERSION}
COMMENT=		PostgreSQL plugin for LibPreludeDB

CONFIGURE_ARGS+=	--with-perl=no
CONFIGURE_ARGS+=	--with-python=no
CONFIGURE_ARGS+=	--with-mysql=no
CONFIGURE_ARGS+=	--with-sqlite3=no

BUILD_DIRS=		plugins/sql

CONFIGURE_ARGS+=	--with-postgresql=${PGSQL_PREFIX}/bin/pg_config

.include "../../mk/pgsql.buildlink3.mk"
.include "../../security/libpreludedb/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
