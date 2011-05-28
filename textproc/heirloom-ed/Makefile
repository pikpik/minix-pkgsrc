# $NetBSD$

PKGNAME=	heirloom-ed-${HEIRLOOM_VER}
CATEGORIES=	textproc editors
LICENSE=	original-bsd

MAKE_FLAGS+=	SUBDIRS="build ed"

NEED_LIBUXRE=	1

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../devel/libuxre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
