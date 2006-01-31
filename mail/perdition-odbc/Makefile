# $NetBSD$
#

PERDITION_COMMENT=	UnixODBC user database module
PERDITION_PKGNAME=	odbc

CONFIGURE_ARGS+=	--with-odbc-includes=${BUILDLINK_PREFIX.unixodbc}/include
CONFIGURE_ARGS+=	--with-odbc-libs=${BUILDLINK_PREFIX.unixodbc}/lib

.include "../../databases/unixodbc/buildlink3.mk"
.include "../perdition/Makefile.common"
