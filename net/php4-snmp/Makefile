# $NetBSD: Makefile,v 1.3 2003/11/07 23:23:18 jdolecek Exp $

MODNAME=		snmp
CATEGORIES+=		net
PKGREVISION=		# empty
COMMENT=		PHP4 extension for SNMP

USE_BUILDLINK2=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-${MODNAME}=${PREFIX}

.include "../../net/net-snmp/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
