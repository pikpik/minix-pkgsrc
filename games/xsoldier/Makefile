# $NetBSD: Makefile,v 1.1 1998/08/01 14:58:18 frueauf Exp $
#

DISTNAME=		xsoldier-0.96
CATEGORIES=		games x11
MASTER_SITES=		http://www.surfline.ne.jp/hachi/xsoldier/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.surfline.ne.jp/hachi/xsoldier.html

USE_IMAKE=		YES
USE_XPM=		YES
NO_INSTALL_MANPAGES=	YES

post-patch:
	${TOUCH} ${WRKSRC}/xsoldier.man

.include "../../mk/bsd.pkg.mk"
