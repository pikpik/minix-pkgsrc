# $NetBSD$
PKGNAME=	postgresql84-dblink-${BASE_VERS}
COMMENT=	dblink module for remote database connections

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	postgresql84-server>=${BASE_VERS}:../../databases/postgresql84-server

.include "../../databases/postgresql84/Makefile.common"

BUILD_DIRS=		src/interfaces/libpq \
			contrib/dblink

INSTALL_DIRS=		contrib/dblink

USE_LIBTOOL=		yes
PKG_LIBTOOL=		${PKG_SHLIBTOOL}

REQD_DIRS+=		${PG_SUBPREFIX}share/doc/postgresql/contrib
REQD_DIRS+=		${PG_SUBPREFIX}share/postgresql/contrib

.include "../../databases/postgresql84-client/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
