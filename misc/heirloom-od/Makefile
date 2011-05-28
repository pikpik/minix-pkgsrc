# $NetBSD$

PKGNAME=	heirloom-od-${HEIRLOOM_VER}
CATEGORIES=	misc

MAKE_FLAGS+=	SUBDIRS="build od"

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
