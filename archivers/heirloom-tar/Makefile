# $NetBSD$

PKGNAME=	heirloom-tar-${HEIRLOOM_VER}
CATEGORIES=	sysutils
LICENSE=	original-bsd

MAKE_FLAGS+=	SUBDIRS="build tar"

NOT_FOR_PLATFORM+=	Interix-*-*

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
