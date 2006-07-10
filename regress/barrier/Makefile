# $NetBSD$
#

DISTNAME=	barrier-1.0
CATEGORIES=	regress
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	rillig@NetBSD.org
COMMENT=	Tests whether pkgsrc barriers work as expected

NO_CHECKSUM=	yes
WRKSRC=		${WRKDIR}

do-build:
	perl -e 'print "hello\n";'

.include "../../mk/bsd.pkg.mk"
