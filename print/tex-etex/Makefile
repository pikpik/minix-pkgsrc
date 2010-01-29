# $NetBSD$
# TeX Live Revision 16381

DISTNAME=	etex
PKGNAME=	tex-${DISTNAME}-2.1
DIST_SUBDIR=	${PKGNAME}-2009

MAINTAINER=	minskim@NetBSD.org
COMMENT=	TeX implementation filling the gap between TeX3 and NTS

CONFLICTS+=	teTeX-texmf<=3.0nb11
DEPENDS+=	tex-plain-[0-9]*:../../print/tex-plain

TEX_TEXMF_DIRS=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
