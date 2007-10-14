# $NetBSD: Makefile,v 1.14 2007/09/21 13:03:46 wiz Exp $
#

.include "../../graphics/3DKit/Makefile.common"
PKGREVISION=	12

DISTFILES=	DevManual.pdf

COMMENT=	Objective-C 3D graphics foundation class library

NO_CONFIGURE=	YES
NO_BUILD=	YES
WRKSRC=		${WRKDIR}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/3DKit
	${INSTALL_DATA} ${WRKSRC}/${DISTFILES} ${PREFIX}/share/doc/3DKit

.include "../../graphics/GlutKit/buildlink3.mk"
.include "../../graphics/GLXKit/buildlink3.mk"
.include "../../graphics/SDLKit/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
