# $NetBSD$

MODNAME=		mhash
CATEGORIES+=		security
PKGREVISION=		# empty
COMMENT=		PHP4 extension for the mhash hash algorithms library

USE_BUILDLINK_ONLY=	yes

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../security/mhash/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
