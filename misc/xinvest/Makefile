# $NetBSD: Makefile,v 1.4 2000/04/17 20:20:28 fredb Exp $

DISTNAME=		xinvest-2.6
CATEGORIES=		misc x11
MASTER_SITES=		http://www.sunsite.auc.dk/xinvest/ \
			${MASTER_SITE_XCONTRIB:=applications/}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.sunsite.auc.dk/xinvest/xinvest.html

USE_IMAKE=		YES
USE_MOTIF=		YES
USE_XPM=		YES

NO_INSTALL_MANPAGES=	YES

post-patch:
	${TOUCH} ${WRKSRC}/Xinvest.man

.include "../../mk/bsd.pkg.mk"
