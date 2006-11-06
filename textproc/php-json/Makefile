# $NetBSD: Makefile,v 1.12 2006/11/06 21:37:37 jdolecek Exp $

MODNAME=		json
PECL_VERSION=		1.2.1
CATEGORIES+=		textproc
COMMENT=		PHP extension for JSON serialization support

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
