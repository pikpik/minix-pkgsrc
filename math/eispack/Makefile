# $NetBSD$

DISTNAME=		eispack-20001129
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		jtb@netbsd.org

WRKSRC=			${WRKDIR}/eispack
USE_LIBTOOL=		YES
UES_FORTRAN=		YES

FOPTS?=			-O3

.include "../../mk/bsd.prefs.mk"

pre-build:
	@${SED} -e 's:%%FORTRAN%%:'${FC}':g;s:%%FOPTS%%:'${FOPTS}':g' \
	< ${FILESDIR}/Makefile > ${WRKSRC}/Makefile

.include "../../mk/bsd.pkg.mk"
