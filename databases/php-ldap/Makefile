# $NetBSD: Makefile,v 1.13 2004/04/25 01:12:49 xtraeme Exp $

MODNAME=		ldap
PKGREVISION=		# empty
CATEGORIES+=		databases
COMMENT=		PHP extension for LDAP database access

USE_BUILDLINK3=		YES

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.openldap}

.include "../../lang/php/ext.mk"
.include "../../databases/openldap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
