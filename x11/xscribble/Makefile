# $NetBSD: Makefile,v 1.2 2000/11/17 14:40:16 wiz Exp $

DISTNAME=	xscribble
PKGNAME=	xscribble-20000616
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.handhelds.org/pub/apps/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.handhelds.org/projects/xscribble.html

USE_IMAKE=	YES
NO_INSTALL_MANPAGES=	YES

post-install:
	${MKDIR} ${PREFIX}/share/examples/xscribble
	${CP} ${WRKSRC}/classifiers/*.cl ${PREFIX}/share/examples/xscribble

.include "../../mk/bsd.pkg.mk"
