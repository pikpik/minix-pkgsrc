# $NetBSD: Makefile,v 1.6 2004/04/24 23:25:23 xtraeme Exp $

MODNAME=		sysvshm
CATEGORIES+=		devel
PKGREVISION=		# empty
COMMENT=		PHP extension for SysV shared memory support

USE_BUILDLINK3=		YES

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
