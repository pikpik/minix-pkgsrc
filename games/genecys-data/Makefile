# $NetBSD$
#

DISTNAME=		genecys-data-0.1
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=genecys/}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://genecys.sourceforge.net/
COMMENT=		Game datafiles for Genecys

WRKSRC=			${WRKDIR}
NO_BUILD=		YES
NO_CONFIGURE=		YES

do-extract:
do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/genecys
	cd ${PREFIX}/share/genecys && \
		${GZCAT} ${DISTDIR}/${DISTFILES} | ${GTAR} xmf -
	${CHOWN} -R ${ROOT_USER}:games ${PREFIX}/share/genecys

.include "../../mk/bsd.pkg.mk"
