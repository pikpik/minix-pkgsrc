# $NetBSD$
#

PKGNAME=	prc-tools-gcc-${PRC_TOOLS_VERS}

BASE_DIST=	gcc
BASE_VERS=	2.95.2

DEPENDS+=	prc-tools-binutils>=2.0:../../devel/prc-tools-binutils

COMMENT=	gcc for GNU tool chain for Palm cross development

ALL_TARGET=	all-gcc
INSTALL_TARGET=	install-gcc

post-install:
	@${RMDIR} ${PREFIX}/m68k-palmos/include

.include "../../devel/prc-tools/Makefile.common"
