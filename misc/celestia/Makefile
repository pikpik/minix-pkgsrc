# $NetBSD: Makefile,v 1.4 2004/04/24 18:53:40 snj Exp $

COMMENT=	Free real-time 3D space simulator

USE_PKGINSTALL=		yes

EGDIR=		${PREFIX}/share/examples/celestia
CONF_FILES=	${EGDIR}/celestia.cfg.default ${PKG_SYSCONFDIR}/celestia.cfg

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/celestia.cfg ${EGDIR}/celestia.cfg.default

.include "../../misc/celestia/Makefile.common"
