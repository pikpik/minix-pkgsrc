# $NetBSD: Makefile,v 1.8 2000/08/10 17:50:08 pooka Exp $
#

.include		"../nethack-lib/Makefile.common"

PKGNAME=		nethack-x11-${NETHACK_VERSION}

CATEGORIES+=		x11

DEPENDS+=		nethack-lib-${NETHACK_VERSION}:../nethack-lib

USE_X11=		YES
USE_XPM=		YES
ALL_TARGET=		nethack
INSTALL_TARGET=		binfiles
MAKE_ENV+=		GTYPE=-x11

PATCHFILES+=		${PKGSRCDIR}/games/nethack-lib/patches/patch-*
ALLFILES=		${DISTFILES}	# don't checksum shared patches

.include "../../mk/bsd.pkg.mk"
