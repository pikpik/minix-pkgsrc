# $NetBSD: Makefile,v 1.2 2010/05/24 06:08:37 minskim Exp $

DISTNAME=	hyphen-ukrainian
PKGNAME=	tex-${DISTNAME}-2010
TEXLIVE_REV=	20144

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Ukrainian

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	ukrainian loadhyph-uk.tex
TEX_HYPHEN_DEF+=	\addlanguage{ukrainian}{loadhyph-uk.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['ukrainian']={ \
			\\tloader='loadhyph-uk.tex', \
			\\tlefthyphenmin=2, \
			\\trighthyphenmin=2, \
			\\tsynonyms={}, \
			\\tpatterns='hyph-uk.pat.txt', \
			\\thyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
