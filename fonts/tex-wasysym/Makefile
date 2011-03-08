# $NetBSD$

DISTNAME=	wasysym
PKGNAME=	tex-${DISTNAME}-2.0
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	LaTeX support file to use the WASY2 fonts

CONFLICTS=	teTeX-texmf<=3.0nb29
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-wasy-[0-9]*:../../fonts/tex-wasy

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
