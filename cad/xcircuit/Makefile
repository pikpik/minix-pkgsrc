# $NetBSD$
#

DISTNAME=	xcircuit-2.1b7
CATEGORIES=	cad graphics
MASTER_SITES=	http://bach.ece.jhu.edu/~tim/programs/xcircuit/archive/

MAINTAINER=	jasontd@indigo.ie
HOMEPAGE=	http://bach.ece.jhu.edu/~tim/programs/xcircuit/

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_IMAKE=	yes
USE_X11BASE=	yes
USE_XPM=	yes

post-build:
	${RM} -fr ${WRKSRC}/examples/CVS
	${MV} -f ${WRKSRC}/examples/.xcircuitrc ${WRKSRC}/examples/xcircuitrc

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/xcircuit/
	${INSTALL_DATA} ${WRKSRC}/examples/* ${PREFIX}/share/examples/xcircuit

.include "../../mk/bsd.pkg.mk"
