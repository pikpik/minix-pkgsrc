# $NetBSD: Makefile,v 1.4 2002/02/28 06:17:18 jlam Exp $

MODNAME=		pgsql
CATEGORIES+=		databases
PKGREVISION=		# empty
COMMENT=		PHP4 extension for PostgreSQL databases

USE_BUILDLINK2=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.postgresql-lib}

.include "../../databases/postgresql-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
