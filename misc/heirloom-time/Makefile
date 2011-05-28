# $NetBSD$

PKGNAME=	heirloom-time-${HEIRLOOM_VER}
CATEGORIES=	misc time

MAKE_FLAGS+=	SUBDIRS="build time"

NOT_FOR_PLATFORM+=	NetBSD-*-*

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
