# $NetBSD: Makefile,v 1.2 2003/03/28 21:14:22 wiz Exp $
#

DISTNAME=	wwl-1.2
WRKSRC=		${WRKDIR}/wwl
CATEGORIES=	ham
MASTER_SITES=	http://www.ibiblio.org/pub/Linux/apps/ham/

MAINTAINER=	dawszy@arhea.net
#HOMEPAGE=	not known
COMMENT=	calculates distance (qrb)

NO_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wwl ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
