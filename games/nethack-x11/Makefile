# $NetBSD: Makefile,v 1.7 2000/03/27 08:54:56 tron Exp $
#

.include		"../nethack-lib/Makefile.common"

PKGNAME=		nethack-x11-${NETHACK_VERSION}

CATEGORIES+=		x11

DEPENDS+=		nethack-lib-${NETHACK_VERSION}:../nethack-lib
DEPENDS+=		xpm-3.4k:../../graphics/xpm

USE_X11=		yes
ALL_TARGET=		nethack
INSTALL_TARGET=		binfiles
MAKE_ENV+=		GTYPE=-x11

PATCHFILES+=		${PKGSRCDIR}/games/nethack-lib/patches/patch-*
ALLFILES=		${DISTFILES}	# don't checksum shared patches

.include "../../mk/bsd.pkg.mk"
