# $NetBSD: Makefile,v 1.10 2001/02/16 15:10:54 wiz Exp $
#

.include		"../nethack-lib/Makefile.common"

PKGNAME=		nethack-lib-${NETHACK_VERSION}

COMMENT=		data files for Nethack

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./sys/unix/setup.sh
ALL_TARGET=		datastuff
INSTALL_TARGET=		manpages install-dat

.if ${OPSYS} == "SunOS"
MAKE_FLAGS+=     	CC=gcc CPPFLAGS=
.endif

.include "../../mk/bsd.pkg.mk"
