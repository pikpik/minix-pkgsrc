# $NetBSD$
#

LIBGDA_PROVIDER=	postgres

.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-postgres=${BUILDLINK_PREFIX.postgresql-lib}

.include "../../databases/postgresql-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
