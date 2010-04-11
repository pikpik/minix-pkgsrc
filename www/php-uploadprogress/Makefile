# $NetBSD$
#

MODNAME=		uploadprogress
PECL_VERSION=		1.0.1
PKGNAME=		${PHP_PKG_PREFIX}-${DISTNAME}
CATEGORIES=		www

MAINTAINER=		mbowie@buzmo.com
COMMENT=		PHP extension to track progress of a file upload

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
