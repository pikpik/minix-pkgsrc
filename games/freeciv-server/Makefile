# $NetBSD$

PKGNAME=		${DISTNAME:S/-/-server-/}

DEPENDS+=		freeciv-share-1.10.0:../../games/freeciv-share

CONFIGURE_ARGS+=	--enable-client=no --disable-make-data

do-install:
	cd ${WRKSRC}/server; ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_TARGET}

.include "../../games/freeciv-share/Makefile.common"
