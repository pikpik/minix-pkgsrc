# $NetBSD: Makefile,v 1.1.1.1 2005/10/09 13:11:18 jdolecek Exp $

PDO_DRIVER=		odbc
PDO_COMMENT=		ODBC
PDO_VERSION=		1.0

.include "../../databases/php-pdo/module.mk"

CONFIGURE_ARGS+=	--with-${PKGMODNAME}=unixodbc,${BUILDLINK_PREFIX.unixodbc}

.include "../../databases/unixodbc/buildlink3.mk"
.include "../../databases/php-pdo/buildlink3.mk"
