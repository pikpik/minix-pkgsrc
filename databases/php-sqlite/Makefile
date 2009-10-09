# $NetBSD: Makefile,v 1.10 2009/10/06 05:05:43 taca Exp $

MODNAME=		sqlite
PECL_VERSION=		1.0.3
CATEGORIES+=		databases
COMMENT=		PHP extension for SQLite 2.x databases

#
# PECL_VERSION exists for temporary workaround and it should be removed
# after next release of lang/php5.
#

PHP_VERSIONS_ACCEPTED=	5

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=		php-sqlite-[0-9]*

CONFIGURE_ARGS+=	--with-${PKGMODNAME}=shared,${BUILDLINK_PREFIX.sqlite}
CONFIGURE_ENV+=		PHP_PDO=no

.include "../../lang/php/ext.mk"
.include "../../databases/sqlite/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
