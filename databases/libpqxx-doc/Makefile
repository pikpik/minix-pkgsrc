# $NetBSD: Makefile,v 1.1.1.1 2004/01/07 13:38:28 is Exp $
#

PKGNAME=	libpqxx-doc-${LIBPQXX_VERSION}
PKGREVISION=	1

.include "../../databases/libpqxx/Makefile.common"

COMMENT=	Documentation for libpqxx

NO_CONFIGURE=	yes
NO_BUILD=	yes

PQXXDOCSRC=	${WRKSRC}/doc/html
PQXXDOC=	${PREFIX}/share/doc/libpqxx
INSTALLATION_DIRS+=	${PQXXDOC}/Reference ${PQXXDOC}/Tutorial
INSTALLATION_DIRS+=	share/examples/libpqxx

do-install:
	${INSTALL_DATA} ${PQXXDOCSRC}/Reference/*.html ${PQXXDOC}/Reference
	${INSTALL_DATA} ${PQXXDOCSRC}/Reference/doxygen.* ${PQXXDOC}/Reference
	${INSTALL_DATA} ${PQXXDOCSRC}/Tutorial/*.html	${PQXXDOC}/Tutorial
	${INSTALL_DATA} ${WRKSRC}/test/*.cxx ${PREFIX}/share/examples/libpqxx

.include "../../mk/bsd.pkg.mk"
