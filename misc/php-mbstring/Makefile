# $NetBSD: Makefile,v 1.10 2009/02/21 12:56:12 adrianp Exp $

MODNAME=		mbstring
CATEGORIES+=		misc
COMMENT=		PHP extension for multibyte characters support (currently, Japanese only)

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-mbstring-[0-9]*

USE_PHP_EXT_PATCHES=	yes

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
