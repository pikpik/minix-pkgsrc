# $NetBSD: $
#

DISTNAME=		pdflib-0.6
CATEGORIES=		print
MASTER_SITES=		http://www.ifconnection.de/~tm/software/pdflib/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.ifconnection.de/~tm/software/pdflib/

BUILD_DEPEND+=		gmake:../../devel/

USE_GMAKE=		yes

# the next is a empty target, as pdflib itself does not have a install
# target. The real install is done by scripts/pre-install
do-install:

.include "../../mk/bsd.pkg.mk"
