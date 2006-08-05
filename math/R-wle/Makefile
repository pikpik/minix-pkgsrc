# $NetBSD: Makefile,v 1.2 2006/02/05 23:10:01 joerg Exp $
#

CATEGORIES=             math
MASTER_SITES=           ${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=             mchittur@cs.nmsu.edu
HOMEPAGE=               ${R_HOMEPAGE_BASE}/wle.html
COMMENT=		Provides approach to robustness via Weighted Likelihood Estimation

R_PKGNAME=		wle
R_PKGVER=               0.9-2
USE_LANGUAGES+=		c fortran

.include "../../math/R/Makefile.extension"
.include "../../math/blas/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
