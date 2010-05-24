# $NetBSD: Makefile,v 1.1.1.1 2009/04/15 07:42:52 minskim Exp $

DISTNAME=	hyphen-latin
PKGNAME=	tex-${DISTNAME}-2009
TEXLIVE_REV=	13822

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for the Latin language

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	latin loadhyph-la.tex
TEX_HYPHEN_DEF+=	\addlanguage{latin}{loadhyph-la.tex}{}{2}{2}

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
