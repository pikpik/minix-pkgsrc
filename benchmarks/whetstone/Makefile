# $NetBSD$

DISTNAME=		whetstone
PKGNAME=		whetstone-1.2
CATEGORIES=		benchmarks
MASTER_SITES=		http://www.netlib.org/benchmark/
EXTRACT_SUFX=		.c

MAINTAINER=		root@garbled.net

NO_WRKSUBDIR=		yes

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/whetstone.c ${WRKSRC}

do-build:
	(cd ${WRKSRC} ; cc -O2 -o whetstone whetstone.c -lm)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/whetstone ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
