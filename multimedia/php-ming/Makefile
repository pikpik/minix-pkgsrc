# $NetBSD$

MODNAME=		ming
CATEGORIES+=		multimedia

MAINTAINER=		obata@lins.jp
COMMENT=		PHP extension for Ming library

CONFIGURE_ARGS+=	--with-${MODNAME}=${BUILDLINK_PREFIX.ming}

.include "../../lang/php/ext.mk"
.include "../../multimedia/ming/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
