# $NetBSD: Makefile,v 1.4 1998/07/04 09:18:55 mycroft Exp $
#

DISTNAME=		xwave-0.6
WRKSRC=			${WRKDIR}/xwave
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/sound/editors

MAINTAINER=		hubertf@netbsd.org

DEPENDS+=		xpm-*:../../graphics/xpm

USE_IMAKE=		yes

post-patch:
	cd ${WRKSRC} ; ${MV} src/XWave src/XWave.ad
	cd ${WRKSRC} ; ${TOUCH} src/xwave.man

.include "../../mk/bsd.pkg.mk"
