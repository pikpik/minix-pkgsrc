# $NetBSD: Makefile,v 1.6 2004/04/24 23:25:23 xtraeme Exp $

MODNAME=		gmp
CATEGORIES+=		devel math
PKGREVISION=		# empty
COMMENT=		PHP extension for arbitrary precision math

USE_BUILDLINK3=		YES

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.gmp}

.include "../../lang/php/ext.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
