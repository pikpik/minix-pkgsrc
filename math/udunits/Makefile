# $NetBSD$

DISTNAME=		udunits
PKGNAME=		udunits-1.11.7
CATEGORIES=		math devel
MASTER_SITES=		http://www.unidata.ucar.edu/packages/udunits/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		jtb@netbsd.org
HOMEPAGE=		http://www.unidata.ucar.edu/packages/udunits/

WRKSRC=			${WRKDIR}/${PKGNAME}/src
DIST_SUBDIR=		${PKGNAME}
GNU_CONFIGURE=		yes
CPPFLAGS+=		-Df2cFortran -Dunix
CONFIGURE_ENV+=		"CPPFLAGS=${CPPFLAGS}"
USE_PERL5=		yes
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/UDUNITS/.packlist

.include "../../mk/bsd.pkg.mk"
