# $NetBSD: Makefile,v 1.5 2006/04/13 19:14:45 cube Exp $
.include "../../sysutils/gkrellm/Makefile.common"

PKGREVISION=		#
GKRELLM_PKGBASE=	gkrellm-share

COMMENT=		GKrellM2 locale files

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		msgfmt
USE_PKGLOCALEDIR=	yes

MAKE_ENV+=		MODULES=po
INSTALL_MAKE_FLAGS=	LOCALEDIR=${DESTDIR}${PREFIX}/${PKGLOCALEDIR}/locale

INSTALLATION_DIRS=	share/gkrellm2 ${PKGLOCALEDIR}/locale

post-install:
	${INSTALL_DATA} ${GKRELLM_SRCDIR}/README ${GKRELLM_SRCDIR}/COPYRIGHT ${DESTDIR}${PREFIX}/share/gkrellm2

.include "../../mk/bsd.pkg.mk"
