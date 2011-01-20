# $NetBSD: Makefile,v 1.2 2010/04/15 20:44:34 minskim Exp $

DISTNAME=	pgfplots
PKGNAME=	tex-${DISTNAME}-1.4.1
TEXLIVE_REV=	19839

MAINTAINER=	minskim@NetBSD.org
COMMENT=	LaTeX package to create normal/logarithmic plots

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
