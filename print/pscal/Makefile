# $NetBSD$
#

DISTNAME=	pscal-1.14
CATEGORIES=	print
MASTER_SITES=	http://www.panix.com/~mbh/pscal/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.panix.com/~mbh/projects.html
COMMENT=	produces simple, nice-looking PostScript calendars

do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pscal ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pscal
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/pscal

.include "../../mk/bsd.pkg.mk"
