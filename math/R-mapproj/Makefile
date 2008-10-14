# $NetBSD: Makefile,v 1.3 2007/02/22 19:26:46 wiz Exp $
#

CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		${R_HOMEPAGE_BASE}/mapproj/
COMMENT=		Converts latitude/longitude into projected coordinates

R_PKGNAME=		mapproj
R_PKGVER=		1.1-7.2

DEPENDS+=		R-maps>=2.0.40:../../math/R-maps

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
