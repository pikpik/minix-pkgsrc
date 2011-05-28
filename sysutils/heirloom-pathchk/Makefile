# $NetBSD$

PKGNAME=	heirloom-pathchk-${HEIRLOOM_VER}
CATEGORIES=	sysutils misc

MAKE_FLAGS+=	SUBDIRS="build pathchk"

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
