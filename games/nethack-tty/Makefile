# $NetBSD: Makefile,v 1.6 2000/03/27 08:54:56 tron Exp $
#

.include		"../nethack-lib/Makefile.common"

PKGNAME=		nethack-tty-${NETHACK_VERSION}

DEPENDS+=		nethack-lib-${NETHACK_VERSION}:../nethack-lib

ALL_TARGET=		nethack
INSTALL_TARGET=		binfiles
MAKE_ENV+=		GTYPE=-tty

PATCHDIR=		"${.CURDIR}/../nethack-lib/patches"

.include "../../mk/bsd.pkg.mk"
