# $NetBSD: Makefile,v 1.2 2001/04/30 15:26:41 wiz Exp $
#

.include "../../devel/prc-tools/Makefile.common"

PKGNAME=	prc-tools-gcc-${PRC_TOOLS_VERS}
COMMENT=	gcc for GNU tool chain for Palm cross development

BASE_DIST=	gcc
BASE_VERS=	2.95.2

BUILD_DEPENDS+=	autoconf-*:../../devel/autoconf
DEPENDS+=	prc-tools-binutils>=2.0:../../devel/prc-tools-binutils

ALL_TARGET=	all-gcc
INSTALL_TARGET=	install-gcc

post-install:
	@${RMDIR} ${PREFIX}/m68k-palmos/include

.include "../../mk/bsd.pkg.mk"
