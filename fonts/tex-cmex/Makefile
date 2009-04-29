# $NetBSD$
# TeX Live Revision 7340

DISTNAME=	cmex
PKGNAME=	tex-${DISTNAME}-2008.7340

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Support for cmex fonts from TeXTrace project

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-ams-[0-9]:../../print/tex-ams

TEX_MIXEDMAP_FILES+=	ttcmex.map

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
