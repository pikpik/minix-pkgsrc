# $NetBSD: Makefile,v 1.6 2002/03/13 17:36:41 fredb Exp $

DISTNAME=	xcircuit-2.2.0
PKGREVISION=	1
CATEGORIES=	cad graphics
MASTER_SITES=	http://bach.ece.jhu.edu/~tim/programs/xcircuit/archive/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://bach.ece.jhu.edu/~tim/programs/xcircuit/
COMMENT=	Drawing program for X11 (especially for circuits)

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_IMAKE=	yes
USE_X11BASE=	yes
USE_XPM=	yes

post-extract:
	${RM} -fr ${WRKSRC}/examples/CVS
	${MV} -f ${WRKSRC}/examples/.xcircuitrc ${WRKSRC}/examples/xcircuitrc
	${TOUCH} ${WRKSRC}/menudep.h

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/xcircuit/
	${INSTALL_DATA} ${WRKSRC}/examples/* ${PREFIX}/share/examples/xcircuit/

.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
