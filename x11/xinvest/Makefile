# $NetBSD: Makefile,v 1.2 1998/08/24 01:00:26 hubertf Exp $

DISTNAME=		xinvest-2.5.1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.sunsite.auc.dk/xinvest/xinvest.html

DEPENDS+=		xpm-3.4k:../../graphics/xpm

USE_IMAKE=		yes
USE_MOTIF=		yes
NO_INSTALL_MANPAGES=	yes

post-patch:
	${TOUCH} ${WRKSRC}/Xinvest.man

.include "../../mk/bsd.pkg.mk"
