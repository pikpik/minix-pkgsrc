# $NetBSD: Makefile,v 1.5 2004/04/25 00:18:14 xtraeme Exp $

MODNAME=		sockets
CATEGORIES+=		net
PKGREVISION=		# empty
COMMENT=		PHP extension for sockets support

USE_BUILDLINK3=		YES

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
