# $NetBSD$
#

DISTNAME=	yacas-1.0.28
CATEGORIES=	math
MASTER_SITES=	http://www.xs4all.nl/~apinkus/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.xs4all.nl/~apinkus/yacas.html

GNU_CONFIGURE=	YES

post-patch:
	cd ${WRKSRC}; ${SED} 's|@prefix@|${PREFIX}|g' yacas.sh.in > \
	  yacas.sh

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/yacas.sh ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
