# $NetBSD: Makefile,v 1.6 2004/04/25 01:12:49 xtraeme Exp $

MODNAME=		dbase
CATEGORIES+=		databases
PKGREVISION=		# empty
COMMENT=		PHP extension for dBase database access

USE_BUILDLINK3=		YES

CONFIGURE_ARGS+=	--with-${MODNAME}=shared

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
