# $NetBSD: Makefile,v 1.1.1.1 2005/10/09 13:11:18 jdolecek Exp $

PDO_DRIVER=		dblib
PDO_COMMENT=		FreeTDS/Sybase/MS SQL
PDO_VERSION=		1.0

.include "../../databases/php-pdo/module.mk"

CONFIGURE_ARGS+=	--with-${PKGMODNAME}=shared,${BUILDLINK_DIR}/freetds

# requires 0.63 version to compile, doesn't compile with 0.61
BUILDLINK_DEPENDS.freetds+=	freetds>=0.63

.include "../../databases/freetds/buildlink3.mk"
.include "../../databases/php-pdo/buildlink3.mk"
