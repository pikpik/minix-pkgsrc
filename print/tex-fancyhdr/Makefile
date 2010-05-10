# $NetBSD: Makefile,v 1.2 2010/02/19 18:19:45 minskim Exp $

DISTNAME=	fancyhdr
PKGNAME=	tex-${DISTNAME}-3.1
PKGREVISION=	1
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Extensive control of page headers and footers in LaTeX2e

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
