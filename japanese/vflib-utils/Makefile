# $NetBSD$

PKGNAME=		ja-vflib-utils-${VFLIB_VERSION}

DEPENDS+=		ja-vflib-lib-${VFLIB_VERSION}:../../japanese/vflib-lib

USE_X11=		# defined
CONFIGURE_ARGS+=	--enable-tools --with-x

ALL_TARGET=		build-tools
INSTALL_TARGET=		install-tools

.include "../../japanese/vflib-lib/Makefile.common"
