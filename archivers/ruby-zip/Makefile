# $NetBSD$

DISTNAME=	rubyzip-0.5.12
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby//}
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rubyzip/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rubyzip.sourceforge.net/
COMMENT=	Ruby module for reading and writing zip files

NO_BUILD=		yes
USE_RUBY_INSTALL=	yes

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
