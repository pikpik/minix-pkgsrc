# $NetBSD$
#

DISTNAME=	yaesu-0.12
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_SUNSITE:=apps/ham/}

MAINTAINER=	dawszy@arhea.net
#HOMEPAGE=	not known
COMMENT=	control interface for Yaesu FT-890 HF transceiver

WRKSRC=		${WRKDIR}/yaesu
NO_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/yaesu ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/yaesu.README

.include "../../mk/bsd.pkg.mk"
