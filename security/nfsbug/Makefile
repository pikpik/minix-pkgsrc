# $NetBSD: Makefile,v 1.3 2001/02/17 17:49:56 wiz Exp $

DISTNAME=	nfsshell-1.0
WRKSRC=		${WRKDIR}/nfsbug
CATEGORIES=	net security
MASTER_SITES=	http://www.asmodeus.com/archive/Xnix/
DISTFILES=	nfsBugFerret.tgz \
		nfsShell.c

MAINTAINER=	packages@netbsd.org
COMMENT=	NFS security verification suite

EXTRACT_ONLY=   nfsBugFerret.tgz

# doesn't build on alpha, pmax, sparc, or vax.  In fact
# the only platform where I've been told it does work is
# i386.
NOT_FOR_PLATFORM=	*-*-alpha *-*-mips* *-*-sparc *-*-vax

post-extract:
	${CP} ${DISTDIR}/nfsShell.c ${WRKSRC}/nfsshell.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nfsbug ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/nfsshell ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
