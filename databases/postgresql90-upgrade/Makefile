# $NetBSD$

PKGNAME=	postgresql90-upgrade-${BASE_VERS}
COMMENT=	PostgreSQL binary upgrade tool
MAINTAINER=	pkgsrc-users@NetBSD.org

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	postgresql90-server>=${BASE_VERS}:../../databases/postgresql90-server

.include "../../databases/postgresql90/Makefile.common"

BUILD_DIRS+=		contrib/pg_upgrade

LIBS.SunOS+=	-lintl

.include "../../databases/postgresql90-client/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
