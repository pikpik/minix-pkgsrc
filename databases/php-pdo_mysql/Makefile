# $NetBSD: Makefile,v 1.3 2005/09/18 15:22:11 jdolecek Exp $

PDO_DRIVER=		mysql
PDO_COMMENT=		MySQL

CONFIGURE_ARGS+=	--with-${PKGMODNAME}=shared,${BUILDLINK_PREFIX.mysql-client}

.include "../../mk/mysql.buildlink3.mk"
.include "../../databases/php-pdo/module.mk"
