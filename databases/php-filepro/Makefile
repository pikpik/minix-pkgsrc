# $NetBSD: Makefile,v 1.6 2004/04/25 01:12:49 xtraeme Exp $

MODNAME=		filepro
CATEGORIES+=		databases
PKGREVISION=		# empty
COMMENT=		PHP extension for read-only filePro database access

USE_BUILDLINK3=		YES

CONFIGURE_ARGS+=	--with-${MODNAME}=shared

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
