# $NetBSD: Makefile,v 1.7 2006/02/05 23:11:06 joerg Exp $

MODNAME=		wddx
PKGREVISION=		3
CATEGORIES+=		textproc
COMMENT=		PHP extension for WDDX support


CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

USE_PHP_EXT_PATCHES=	# defined

# appease some PHP build assumpsions
CFLAGS+=	-I${BUILDLINK_DIR}/include/libxml2 \
		-I${BUILDLINK_DIR}/include/php/ext/date/lib
		

.include "../../lang/php/phpversion.mk"

# link against libxml2 on PHP5 (the code is using expat compat
# build wrapper)
.if ${PKG_PHP_VERSION} == 5
.include "../../textproc/libxml2/buildlink3.mk"
.else
.include "../../textproc/expat/buildlink3.mk"
.endif

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
