# $NetBSD: Makefile,v 1.3 2004/11/05 17:11:39 jdolecek Exp $

MODNAME=		ldap
PKGREVISION=		# empty
CATEGORIES+=		databases
COMMENT=		PHP extension for LDAP database access


CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.openldap}

.include "../../lang/php/ext.mk"
.include "../../databases/openldap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
