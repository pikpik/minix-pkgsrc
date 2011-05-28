# $NetBSD$

PKGNAME=	heirloom-hd-${HEIRLOOM_VER}
CATEGORIES=	misc sysutils

MAKE_FLAGS+=	SUBDIRS="build hd"

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	${.CURDIR}/DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
