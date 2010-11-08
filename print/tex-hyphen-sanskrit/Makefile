# $NetBSD: Makefile,v 1.2 2010/05/24 06:08:36 minskim Exp $

DISTNAME=	hyphen-sanskrit
PKGNAME=	tex-${DISTNAME}-2010
TEXLIVE_REV=	20144

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Sanskrit

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	sanskrit loadhyph-sa.tex
TEX_HYPHEN_DEF+=	\addlanguage{sanskrit}{loadhyph-sa.tex}{}{1}{5}
TEX_HYPHEN_LUA+=	['sanskrit']={ \
			\\tloader='loadhyph-sa.tex', \
			\\tlefthyphenmin=1, \
			\\trighthyphenmin=5, \
			\\tsynonyms={}, \
			\\tpatterns='hyph-sa.pat.txt', \
			\\thyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
