# $NetBSD: Makefile,v 1.3 2005/09/18 15:22:11 jdolecek Exp $

PDO_DRIVER=		sqlite
PDO_COMMENT=		SQLite v3

CONFIGURE_ARGS+=	--with-${PKGMODNAME}=shared,${BUILDLINK_PREFIX.sqlite3}

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../databases/php-pdo/module.mk"
