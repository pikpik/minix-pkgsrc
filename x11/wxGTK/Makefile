# $NetBSD: Makefile,v 1.41 2005/07/21 16:30:01 wiz Exp $
#

.include "Makefile.common"

PKGREVISION=		5
COMMENT=		GTK-based implementation of the wxWidgets GUI library

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENCE.txt ${DOCDIR}/LICENSE

.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
