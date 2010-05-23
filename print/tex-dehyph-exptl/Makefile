# $NetBSD: Makefile,v 1.1.1.1 2009/04/15 05:25:38 minskim Exp $

DISTNAME=	dehyph-exptl
PKGNAME=	tex-${DISTNAME}-0.20
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Experimental hyphenation patterns for the German language

CONFLICTS+=	teTeX-texmf<=3.0nb12

TEX_HYPHEN_DAT+=	german-x-2009-06-19 dehypht-x-2009-06-19.tex
TEX_HYPHEN_DAT+=	= german-x-latest
TEX_HYPHEN_DAT+=	ngerman-x-2009-06-19 dehyphn-x-2009-06-19.tex
TEX_HYPHEN_DAT+=	= ngerman-x-latest
TEX_HYPHEN_DEF+=	\addlanguage{german-x-2009-06-19}{dehypht-x-2009-06-19.tex}{}{2}{2}
TEX_HYPHEN_DEF+=	\addlanguage{german-x-latest}{dehypht-x-2009-06-19.tex}{}{2}{2}
TEX_HYPHEN_DEF+=	\addlanguage{ngerman-x-2009-06-19}{dehyphn-x-2009-06-19.tex}{}{2}{2}
TEX_HYPHEN_DEF+=	\addlanguage{ngerman-x-latest}{dehyphn-x-2009-06-19.tex}{}{2}{2}

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
