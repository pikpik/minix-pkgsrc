# $NetBSD$

.include "../../www/php4/Makefile.module"

MODNAME=		odbc
CATEGORIES+=		databases
PHP_PKG_VERS=		# empty
COMMENT=		PHP4 extension for ODBC access

USE_BUILDLINK_ONLY=	YES
CONFIGURE_ARGS+=	--with-unixODBC=shared,${BUILDLINK_DIR}

.include "../../databases/unixodbc/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
