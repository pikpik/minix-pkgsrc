# $NetBSD$
#

DISTNAME=		ftplibpp-1.0.1
CATEGORIES=		net devel
MASTER_SITES=		http://home.arcor.de/breitscheid/ftplibpp/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://home.arcor.de/breitscheid/ftplibpp/ftplibpp.html
COMMENT=		C++ class providing ftp client functionality

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ftplibpp
	${INSTALL_DATA} ${WRKSRC}/ftplibpp.html ${PREFIX}/share/doc/ftplibpp

.include "../../mk/bsd.pkg.mk"
