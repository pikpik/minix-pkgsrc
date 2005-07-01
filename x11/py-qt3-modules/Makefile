# $NetBSD: Makefile,v 1.17 2005/06/01 18:03:30 jlam Exp $
#

.include "../../x11/py-qt3-base/Makefile.common"

PKGNAME=		${PYPKGPREFIX}-qt3-modules-${PYQT_VERSION}

COMMENT=		Various Python modules for Qt3

INSTALL_DIRS=	${WRKSRC}/qtcanvas ${WRKSRC}/qtgl ${WRKSRC}/qtnetwork
INSTALL_DIRS+=	${WRKSRC}/qtsql ${WRKSRC}/qttable ${WRKSRC}/qtui
INSTALL_DIRS+=	${WRKSRC}/qtxml

.include "../../x11/py-qt3-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
