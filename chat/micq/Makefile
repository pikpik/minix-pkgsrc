# $NetBSD: Makefile,v 1.1.1.1 2000/12/15 00:36:29 wiz Exp $

DISTNAME=	micq-0.4.6.p1
PKGNAME=	${DISTNAME:S/p//}
CATEGORIES=	chat
MASTER_SITES=	http://micq.ukeer.de/source/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://micq.ukeer.de/

WRKSRC=		${WRKDIR}/${DISTNAME:S/.p/-p/}/src

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/micq ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/micq
	${INSTALL_MAN} ${WRKSRC}/../README ${PREFIX}/share/doc/micq

.include "../../mk/bsd.pkg.mk"
