# $NetBSD: Makefile,v 1.3 2006/12/28 12:12:58 joerg Exp $
#

PKGREVISION=		3

PERDITION_COMMENT=	PostgreSQL user database module
PERDITION_PKGNAME=	postgresql
PERDITION_SKIP_DISABLE=	pg

USE_TOOLS+=	bash:run
REPLACE_BASH+=	perdition/db/postgresql/perditiondb_postgresql_makedb

.include "../../mk/pgsql.buildlink3.mk"
.include "../perdition/Makefile.common"
