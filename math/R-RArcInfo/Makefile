# $NetBSD: Makefile,v 1.4 2008/10/13 11:29:42 markd Exp $
#

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/RArcInfo/
COMMENT=	Read geographical information from Arc/Info
LICENSE=	gnu-gpl-v2

R_PKGNAME=	RArcInfo
R_PKGVER=	0.4-12

DEPENDS+=	R-RColorBrewer>=1.0.5:../../math/R-RColorBrewer

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
