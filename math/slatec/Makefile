# $NetBSD$

DISTNAME=	slatec_src
PKGNAME=	slatec-4.1
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.netlib.org/slatec/ \
		ftp://netlib.bell-labs.com/netlib/slatec/ \
		ftp://www.hensa.ac.uk/mirrors/netlib/slatec/ \
		ftp://netlib.no/netlib/slatec/ \
		ftp://ftp.zib.de/netlib/slatec/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jtb@netbsd.org

WRKSRC=		${WRKDIR}/src

USE_LIBTOOL=	YES
UES_FORTRAN=	YES

FOPTS?=		-O2
MAKE_ENV+=	"FFLAGS=${FOPTS}"

pre-build:
	@${SED} -e 's:%%FORTRAN%%:'${FC}':g' \
	< ${FILESDIR}/Makefile > ${WRKSRC}/Makefile

.include "../../mk/bsd.pkg.mk"
