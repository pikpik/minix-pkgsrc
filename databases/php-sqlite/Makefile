# $NetBSD: Makefile,v 1.8 2008/06/20 01:09:11 joerg Exp $

MODNAME=		sqlite
CATEGORIES+=		databases
COMMENT=		PHP extension for SQLite 2.x databases

PHP_VERSIONS_ACCEPTED=	5

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=		php-sqlite-[0-9]*

CONFIGURE_ARGS+=	--with-${PKGMODNAME}=shared,${BUILDLINK_PREFIX.sqlite}

.include "../../lang/php/ext.mk"
.include "../../databases/sqlite/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
