# $NetBSD: Makefile,v 1.8 2004/04/25 00:23:55 xtraeme Exp $

MODNAME=		bcmath
CATEGORIES+=		math
PKGREVISION=		# empty
COMMENT=		PHP extension for bc-style arbitrary precision math

USE_BUILDLINK3=		YES

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
