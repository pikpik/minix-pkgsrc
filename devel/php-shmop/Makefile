# $NetBSD: Makefile,v 1.5 2005/12/05 20:50:06 rillig Exp $

MODNAME=		shmop
PKGREVISION=		1
CATEGORIES+=		devel
COMMENT=		PHP extension for simple SysV shared memory operations


CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
