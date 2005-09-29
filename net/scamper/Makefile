# $NetBSD$
#

DISTNAME=	scamper-cvs-20050529
PKGNAME=	${DISTNAME:S/-cvs//}
CATEGORIES=	net
MASTER_SITES=	http://www.wand.net.nz/scamper/

MAINTAINER=	rpaulo@NetBSD.org
HOMEPAGE=	http://www.wand.net.nz/scamper/
COMMENT=	Dual-stack traceroute software

INSTALLATION_DIRS=bin

MAKE_FLAGS=	WITH_DEBUG=yes	# recommended by the the software developer

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/scamper ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
