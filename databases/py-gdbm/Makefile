# $NetBSD: Makefile,v 1.12 2000/08/21 21:01:29 hubertf Exp $
#

DISTNAME=	${PY_DISTNAME}
PKGNAME=	py-gdbm-${PY_VERSION}
WRKSRC=		${PY_WRKSRC}
CATEGORIES=	databases
MASTER_SITES=	${PY_MASTER_SITES}

MAINTAINER=	dolecek@ics.muni.cz
HOMEPAGE=	http://www.python.org/doc/lib/module-gdbm.html

DEPENDS+=	gdbm>=1.7.3:../../databases/gdbm

EXTRACT_ELEMENTS=	${PY_MODULES}/gdbmmodule.c

do-configure: python-std-do-configure

do-install:
	${INSTALL_DATA} ${WRKSRC}/gdbmmodule.so ${PY_LIBDIR}/lib-dynload

.include "../../lang/python/Makefile.inc"
.include "../../mk/bsd.pkg.mk"
