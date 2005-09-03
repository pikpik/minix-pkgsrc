# $NetBSD$
#

DISTNAME=	pipebench-0.40
CATEGORIES=	benchmarks
MASTER_SITES=	ftp://ftp.habets.pp.se/pub/synscan/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	ftp://ftp.habets.pp.se/pub/synscan/
COMMENT=	Measures the speed of a pipe

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pipebench ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
