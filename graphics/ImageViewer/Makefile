# $NetBSD: Makefile,v 1.10 2004/03/26 02:27:40 wiz Exp $
#

DISTNAME=	ImageViewer-0.6.2
CATEGORIES=	graphics gnustep
MASTER_SITES=	http://www.nice.ch/~phip/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.nice.ch/~phip/softcorner.html\#img
COMMENT=	GNUstep image display application

WRKSRC=		${WRKDIR}/ImageViewer
NO_CONFIGURE=	yes
USE_BUILDLINK3=	yes
USE_X11=	yes

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
