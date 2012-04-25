# $NetBSD: Makefile,v 1.8 2011/12/17 13:46:28 obache Exp $

MODNAME=		intl
PECL_VERSION=		2.0.0
PECL_LEGACY_VERSION_SCHEME=	yes
CATEGORIES+=		textproc
COMMENT=		PHP extension for i18n
LICENSE=		php

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
