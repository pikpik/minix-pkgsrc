# $NetBSD: Makefile,v 1.2 2000/12/30 21:30:18 hubertf Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		ldap
CATEGORIES+=		databases

DEPENDS+=		openldap-1.2.*:../../databases/openldap

EVAL_PREFIX+=		LDAPDIR=openldap
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${LDAPDIR}

.include "../../mk/bsd.pkg.mk"
