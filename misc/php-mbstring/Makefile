# $NetBSD: Makefile,v 1.7 2004/04/25 00:20:38 xtraeme Exp $

MODNAME=		mbstring
CATEGORIES+=		misc
PKGREVISION=		# empty
COMMENT=		PHP extension for multibyte characters support (currently, Japanese only)

USE_BUILDLINK3=		YES

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
