# $NetBSD: Makefile,v 1.4 2010/09/14 00:18:16 minskim Exp $

DISTNAME=	exam
PKGNAME=	tex-${DISTNAME}-2.4
TEXLIVE_REV=	22585

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Package for typesetting exam scripts

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
