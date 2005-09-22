# $NetBSD: Makefile,v 1.14 2005/07/19 10:17:59 grant Exp $
#

.include		"../nethack-lib/Makefile.common"

PKGNAME=		nethack-tty-${NETHACK_VERSION}
PKGREVISION=		1

COMMENT=		The tty/console based version of NetHack

DEPENDS+=		nethack-lib-${NETHACK_VERSION}nb1:../../games/nethack-lib

BUILD_TARGET=		nethack
INSTALL_TARGET=		binfiles
MAKE_ENV+=		GTYPE=-tty

PATCHDIR=		${.CURDIR}/../nethack-lib/patches

.include "../../mk/bsd.pkg.mk"
