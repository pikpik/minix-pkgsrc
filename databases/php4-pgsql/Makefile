# $NetBSD: Makefile,v 1.7 2001/09/27 23:18:57 jlam Exp $

.include "../php4/Makefile.module"

MODNAME=		pgsql
CATEGORIES+=		databases
PHP_PKG_VERS=		# empty
COMMENT=		PHP4 extension for PostgreSQL databases

USE_BUILDLINK_ONLY=	YES
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../databases/postgresql-lib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
