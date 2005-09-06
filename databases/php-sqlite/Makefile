# $NetBSD: Makefile,v 1.4 2005/04/11 21:45:14 tv Exp $

MODNAME=		SQLite
PKGMODNAME=		sqlite
PKGNAME=		php-${PKGMODNAME}-${PHP_BASE_VERS}.${PECL_VERSION}
PECL_VERSION=		1.0.3
CATEGORIES+=		databases
MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		PHP extension for PostgreSQL databases

PHP_VERSIONS_ACCEPTED=	4

CONFIGURE_ARGS+=	--with-${PKGMODNAME}=shared,${BUILDLINK_PREFIX.sqlite}

.include "../../lang/php/ext.mk"
.include "../../databases/sqlite/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
