# $NetBSD: Makefile,v 1.4 2004/11/05 21:44:44 jdolecek Exp $

MODNAME=		zip
PECL_VERSION=		1.0
CATEGORIES+=		archivers
PKGREVISION=		# empty
COMMENT=		PHP extension for ZIP archive handling

USE_BUILDLINK3=		YES

CONFIGURE_ARGS+=	--with-zip=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../archivers/zziplib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
