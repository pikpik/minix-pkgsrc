# $NetBSD: Makefile,v 1.2 2010/05/24 06:08:34 minskim Exp $

DISTNAME=	hyphen-dutch
PKGNAME=	tex-${DISTNAME}-2010
TEXLIVE_REV=	20144

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Dutch

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	dutch loadhyph-nl.tex
TEX_HYPHEN_DEF+=	\addlanguage{dutch}{loadhyph-nl.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['dutch']={ \
			\\tloader='loadhyph-nl.tex', \
			\\tlefthyphenmin=2, \
			\\trighthyphenmin=2, \
			\\tsynonyms={}, \
			\\tpatterns='hyph-nl.pat.txt', \
			\\thyphenation='hyph-nl.hyp.txt', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
