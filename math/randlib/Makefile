# $NetBSD$

DISTNAME=	randlib.c-1.3
PKGNAME=	randlib-1.3
CATEGORIES=	math
MASTER_SITES=	ftp://odin.mdacc.tmc.edu/pub/source/

MAINTAINER=	jtb@netbsd.org
HOMEPAGE=	http://odin.mdacc.tmc.edu/anonftp/page_2.html

USE_LIBTOOL=	YES
WRKSRC=		${WRKDIR}/randlib.c/src

post-patch:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/randlib
	${INSTALL_DATA} ${WRKSRC}/../README ${WRKSRC}/../doc/* \
	${PREFIX}/share/doc/randlib
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/randlib
	${INSTALL_DATA} ${WRKSRC}/../test/* ${PREFIX}/share/examples/randlib
	${INSTALL_DATA} ${WRKSRC}/randlib.h ${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
