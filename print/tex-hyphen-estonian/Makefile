# $NetBSD: Makefile,v 1.1.1.1 2009/04/15 07:33:09 minskim Exp $

DISTNAME=	hyphen-estonian
PKGNAME=	tex-${DISTNAME}-2009
TEXLIVE_REV=	13822

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Estonian

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	estonian loadhyph-et.tex
TEX_HYPHEN_DEF+=	\addlanguage{estonian}{loadhyph-et.tex}{}{2}{3}

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
