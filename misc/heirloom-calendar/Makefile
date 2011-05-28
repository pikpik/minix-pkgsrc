# $NetBSD$

PKGNAME=	heirloom-calendar-${HEIRLOOM_VER}
CATEGORIES=	misc time
LICENSE=	original-bsd

MAKE_FLAGS+=	SUBDIRS="build calendar"

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
