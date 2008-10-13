# $NetBSD: Makefile,v 1.2 2006/02/05 23:09:59 joerg Exp $
#

CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		${R_HOMEPAGE_BASE}/CGIwithR/
COMMENT=		Facilities for the use of R to write CGI scripts

R_PKGNAME=		CGIwithR
R_PKGVER=		0.72

REPLACE_INTERPRETER+=	r
REPLACE.r.old=		.*R
REPLACE.r.new=		${PREFIX}/bin/R
REPLACE_FILES.r=	inst/examples/dangerous.R inst/examples/trivial.R

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
