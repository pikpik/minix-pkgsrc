# $NetBSD: Makefile,v 1.1.1.1 2005/03/23 22:09:50 jmmv Exp $

.include "../../databases/sqlite3/Makefile.common"

PKGNAME:=		${PKGNAME:S/-/-tcl-/}

CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}/lib

BUILD_TARGET=		libtclsqlite3.la
INSTALL_TARGET=		tcl_install
TEST_TARGET=		test

BUILDLINK_DEPENDS.sqlite3+=	sqlite3>=3.2.7

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
