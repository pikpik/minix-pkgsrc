# $NetBSD: Makefile,v 1.2 2008/12/21 21:24:08 adrianp Exp $
#

PKGNAME=	isc-dhcp-${DHVER}
COMMENT=	ISC Dynamic Host Configuration Protocol (DHCP) Base
SUBDIR=		includes common minires dst

.include "options.mk"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PKGBASE}

	${INSTALL_DATA} ${WRKSRC}/README \
		${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/RELNOTES \
		${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/doc/References.txt \
		${PREFIX}/share/doc/${PKGBASE}

.include "../../net/isc-dhcp4/Makefile.common"
.include "../../mk/bsd.pkg.mk"
