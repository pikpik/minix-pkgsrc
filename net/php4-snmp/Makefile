# $NetBSD: Makefile,v 1.1.1.1 2002/07/25 17:09:34 jonb Exp $

MODNAME=		snmp
CATEGORIES+=		net
PKGREVISION=		# empty
COMMENT=		PHP4 extension for SNMP

USE_BUILDLINK2=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-${MODNAME}=${PREFIX}

.include "../../net/ucd-snmp/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
