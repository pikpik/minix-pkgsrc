# $NetBSD$
#

DISTNAME=	netcdf-3.4
WRKSRC=		${WRKDIR}/${DISTNAME}/src
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.unidata.ucar.edu/pub/netcdf/ \
		ftp://ftp.dfd.dlr.de/pub/ucar/netcdf/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.unidata.ucar.edu/packages/netcdf/index.html

DEPENDS+=	fort77-1.14a:../../lang/fort77

CONFIGURE_ENV+=	CPPFLAGS="-Df2cFortran -Dunix"

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

.include "../../mk/bsd.pkg.mk"
