# $NetBSD: Makefile,v 1.1.1.1 2004/10/02 10:10:59 jdolecek Exp $

MODNAME=		shmop
CATEGORIES+=		devel
PKGREVISION=		# empty
COMMENT=		PHP extension for simple SysV shared memory operations

USE_BUILDLINK3=		YES

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
