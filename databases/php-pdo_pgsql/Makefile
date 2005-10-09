# $NetBSD: Makefile,v 1.3 2005/09/18 15:22:11 jdolecek Exp $

PDO_DRIVER=		pgsql
PDO_COMMENT=		PostgreSQL

CONFIGURE_ARGS+=	--with-${PKGMODNAME}=shared,${PGSQL_PREFIX}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../databases/php-pdo/module.mk"
