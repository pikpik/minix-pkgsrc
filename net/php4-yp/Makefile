# $NetBSD$

.include "../../www/php4/Makefile.module"

MODNAME=		yp
CATEGORIES+=		net
PHP_PKG_VERS=		# empty
COMMENT=		PHP4 extension for YP domain support

USE_BUILDLINK_ONLY=	YES
CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../mk/bsd.pkg.mk"
