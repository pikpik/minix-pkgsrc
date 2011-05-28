# $NetBSD$

PKGNAME=	heirloom-news-${HEIRLOOM_VER}
CATEGORIES=	news

MAKE_FLAGS+=	SUBDIRS="build news"

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
