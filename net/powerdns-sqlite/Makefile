# $NetBSD$

.include "../../net/powerdns/Makefile.backend"

PKGNAME=		${DISTNAME:S/pdns/powerdns-sqlite/}
COMMENT=		SQLite backend module for PowerDNS

CONFIGURE_ARGS+=	--with-dynmodules="gsqlite"
CONFIGURE_ARGS+=	--with-sqlite-lib=${BUILDLINK_PREFIX.sqlite}/lib
CONFIGURE_ARGS+=	--with-sqlite-includes=${BUILDLINK_PREFIX.sqlite}/include

.include "../../databases/sqlite/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
