# $NetBSD: Makefile,v 1.2 1999/12/10 13:54:32 soren Exp $

DISTNAME=	swarm-0.26
CATEGORIES=	emulators
MASTER_SITES=	http://www.dcs.gla.ac.uk/~michael/phd/bin/

MAINTAINER=	agc@netbsd.org
HOMEPAGE=	http://www.dcs.gla.ac.uk/~michael/phd/swarm.html

WRKSRC=		${WRKDIR}/swarm/src

do-install:
	${BSD_INSTALL_PROGRAM} ${WRKSRC}/swarm ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/doc/swarm
	${BSD_INSTALL_DATA} ${WRKSRC}/../doc/swarm.pdf ${PREFIX}/share/doc/swarm

.include "../../mk/bsd.pkg.mk"
