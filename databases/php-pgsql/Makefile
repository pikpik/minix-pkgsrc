# $NetBSD: Makefile,v 1.11 2004/07/24 22:45:15 recht Exp $

MODNAME=		pgsql
PKGREVISION=		# empty
CATEGORIES+=		databases
COMMENT=		PHP extension for PostgreSQL databases

USE_BUILDLINK3=		YES

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${PGSQL_PREFIX}

.include "../../lang/php/ext.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
