# $NetBSD: Makefile,v 1.6 2001/02/17 17:22:29 wiz Exp $

MODNAME=		ldap
CATEGORIES+=		databases
PKGREVISION=		# empty
COMMENT=		PHP3 extension for LDAP database access

USE_BUILDLINK_ONLY=	yes

.include "../../www/php3/Makefile.module"

CONFIGURE_ARGS+=	--with-ldap=${BUILDLINK_DIR}
MOD_LIBS+=		-lldap -llber

.include "../../databases/openldap/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
