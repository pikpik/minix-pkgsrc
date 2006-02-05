# $NetBSD: Makefile,v 1.5 2005/12/05 20:50:48 rillig Exp $

MODNAME=		snmp
PKGREVISION=		1
CATEGORIES+=		net
COMMENT=		PHP extension for SNMP


CONFIGURE_ARGS+=	--with-${MODNAME}=${PREFIX}

.include "../../lang/php/ext.mk"
.include "../../net/net-snmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
