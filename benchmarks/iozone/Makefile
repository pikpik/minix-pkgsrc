# $NetBSD: Makefile,v 1.8 2000/03/16 12:16:52 wiz Exp $

DISTNAME=		iozone3_9
PKGNAME=		iozone-3.09
CATEGORIES=		benchmarks
MASTER_SITES=		http://www.iozone.org/src/stable/
EXTRACT_SUFX=		.tar

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.iozone.org/

WRKSRC=			${WRKDIR}/src
MAKEFILE=		makefile

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "NetBSD")
  ALL_TARGET=		NetBSD
.elif (${OPSYS} == "SunOS")
  ALL_TARGET=		Solaris
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/iozone ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/iozone.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
