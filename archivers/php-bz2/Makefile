# $NetBSD: Makefile,v 1.5 2004/04/24 23:13:57 xtraeme Exp $

MODNAME=		bz2
CATEGORIES+=		archivers
PKGREVISION=		# empty
COMMENT=		PHP extension for bzip2 compression

USE_BUILDLINK3=		YES

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.bzip2}

.include "../../lang/php/ext.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
