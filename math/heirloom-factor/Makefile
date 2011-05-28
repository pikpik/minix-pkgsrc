# $NetBSD$

PKGNAME=	heirloom-factor-${HEIRLOOM_VER}
CATEGORIES=	math
LICENSE=	original-bsd

MAKE_FLAGS+=	SUBDIRS="build factor"

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
