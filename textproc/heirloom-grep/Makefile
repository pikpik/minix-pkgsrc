# $NetBSD$

PKGNAME=	heirloom-grep-${HEIRLOOM_VER}
CATEGORIES=	textproc sysutils

MAKE_FLAGS+=	SUBDIRS="build grep"

NEED_LIBUXRE=	1

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../devel/libuxre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
