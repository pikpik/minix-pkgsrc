# $NetBSD$

MODNAME=		snmp
CATEGORIES+=		net
PKGREVISION=		# empty
COMMENT=		PHP4 extension for SNMP

USE_BUILDLINK_ONLY=	YES

BUILD_DEPENDS+= ucd-snmp:../../net/ucd-snmp

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-${MODNAME}=${PREFIX}

.include "../../mk/bsd.pkg.mk"
