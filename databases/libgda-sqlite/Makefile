# $NetBSD$
#

LIBGDA_PROVIDER=	sqlite

.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-sqlite=${BUILDLINK_PREFIX.sqlite}

.include "../../databases/sqlite/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
