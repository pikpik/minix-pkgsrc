# $NetBSD$

.include "../php4/Makefile.module"

MODNAME=		ldap
CATEGORIES+=		databases
PHP_PKG_VERS=		# empty
COMMENT=		PHP4 extension for LDAP database access

USE_BUILDLINK_ONLY=	YES
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../databases/openldap/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
