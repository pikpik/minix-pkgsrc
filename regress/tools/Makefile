# $NetBSD: Makefile,v 1.3 2005/11/24 19:39:23 rillig Exp $
#

DISTNAME=	# not applicable
PKGNAME=	regress-tools-1.1
CATEGORIES=	regress
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	rillig@NetBSD.org
COMMENT=	Test whether the TOOLS do what I expect

NO_CHECKSUM=	yes
WRKSRC=		${WRKDIR}
REGRESS_TESTS=	awk sort tr
USE_TOOLS+=	awk sort tr

do-build:
.for t in ${REGRESS_TESTS}
	${_PKG_SILENT}${_PKG_DEBUG}set -e; cd ${WRKSRC:Q};		\
	${ECHO_MSG} "Running testsuite "${t:Q};				\
	${SH} ${FILESDIR:Q}/${t:Q}-test.sh
.endfor

.include "../../mk/bsd.pkg.mk"
