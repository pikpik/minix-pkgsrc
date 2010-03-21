# $NetBSD: Makefile,v 1.2 2008/06/12 02:14:51 joerg Exp $

MODNAME=		intl
PECL_VERSION=		1.1.1
CATEGORIES+=		textproc
COMMENT=		PHP extension for i18n

PHP_VERSIONS_ACCEPTED=	5

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

USE_LANGUAGES+=		c c++

.include "../../lang/php/ext.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
