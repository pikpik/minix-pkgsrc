# $NetBSD: Makefile,v 1.8 2000/07/17 15:37:15 agc Exp $
#

.include		"../nethack-lib/Makefile.common"

PKGNAME=		nethack-lib-${NETHACK_VERSION}

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./sys/unix/setup.sh
ALL_TARGET=		datastuff
INSTALL_TARGET=		manpages install-dat

DEINSTALL_FILE=		${WRKDIR}/DEINSTALL

.if ${OPSYS} == "SunOS"
MAKE_FLAGS+=     	CC=gcc CPPFLAGS=
.endif

post-build:
	${SED} -e 's|@PREFIX@|${PREFIX}|' ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}

.include "../../mk/bsd.pkg.mk"
