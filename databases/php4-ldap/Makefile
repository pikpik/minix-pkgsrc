# $NetBSD: Makefile,v 1.4 2002/02/01 19:22:55 jlam Exp $

MODNAME=		ldap
CATEGORIES+=		databases
PKGREVISION=		# empty
COMMENT=		PHP4 extension for LDAP database access

USE_BUILDLINK_ONLY=	YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_DIR}
CONFIGURE_ENV+=		PTHREAD_TYPE="${PTHREAD_TYPE}"

.include "../../databases/openldap/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
