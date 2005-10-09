# $NetBSD: Makefile,v 1.3 2005/09/18 15:22:11 jdolecek Exp $

PDO_DRIVER=		odbc
PDO_COMMENT=		ODBC
PECL_VERSION?=		0.9

CONFIGURE_ARGS+=	--with-${PKGMODNAME}=unixodbc,${BUILDLINK_PREFIX.unixodbc}

.include "../../databases/unixodbc/buildlink3.mk"
.include "../../databases/php-pdo/module.mk"
