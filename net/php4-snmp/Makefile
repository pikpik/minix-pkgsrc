# $NetBSD: Makefile,v 1.2 2002/11/05 07:33:18 martti Exp $

MODNAME=		snmp
CATEGORIES+=		net
PKGREVISION=		1
COMMENT=		PHP4 extension for SNMP

USE_BUILDLINK2=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-${MODNAME}=${PREFIX}

.include "../../net/net-snmp/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
