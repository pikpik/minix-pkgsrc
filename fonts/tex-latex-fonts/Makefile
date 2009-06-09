# $NetBSD: Makefile,v 1.2 2009/04/24 06:13:31 minskim Exp $
# TeX Live Revision 12918

DISTNAME=	latex-fonts
PKGNAME=	tex-${DISTNAME}-2008.12918
CATEGORIES=	fonts

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Collection of fonts used in LaTeX distributions

CONFLICTS+=	teTeX-texmf<=3.0nb12

TEX_MIXEDMAP_FILES+=	latex-bsr.map

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
