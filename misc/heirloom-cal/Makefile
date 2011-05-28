# $NetBSD$

PKGNAME=	heirloom-cal-${HEIRLOOM_VER}
CATEGORIES=	misc time
LICENSE=	original-bsd

MAKE_FLAGS+=	SUBDIRS="build cal"

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
