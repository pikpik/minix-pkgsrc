# $NetBSD$

.include "../php4/Makefile.module"

MODNAME=		gmp
CATEGORIES+=		devel math
PHP_PKG_VERS=		# empty
COMMENT=		PHP4 extension for arbitrary precision math

USE_BUILDLINK_ONLY=	YES
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../devel/gmp/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
