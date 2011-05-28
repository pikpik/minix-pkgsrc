# $NetBSD$

PKGNAME=	heirloom-sum-${HEIRLOOM_VER}
CATEGORIES=	misc
LICENSE=	original-bsd

MAKE_FLAGS+=	SUBDIRS="build sum"

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
