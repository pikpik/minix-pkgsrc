# $NetBSD: Makefile,v 1.1.1.1 2005/10/09 13:11:18 jdolecek Exp $

PDO_DRIVER=		mysql
PDO_COMMENT=		MySQL
PDO_VERSION=		1.0.1

.include "../../databases/php-pdo/module.mk"

CONFIGURE_ARGS+=	--with-${PKGMODNAME}=shared,${BUILDLINK_PREFIX.mysql-client}

.include "../../mk/mysql.buildlink3.mk"
.include "../../databases/php-pdo/buildlink3.mk"
