# $NetBSD: Makefile,v 1.2 2010/05/24 06:08:36 minskim Exp $

DISTNAME=	hyphen-slovenian
PKGNAME=	tex-${DISTNAME}-2010
TEXLIVE_REV=	20144

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Slovenian

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	slovenian loadhyph-sl.tex
TEX_HYPHEN_DAT+=	= slovene
TEX_HYPHEN_DEF+=	\addlanguage{slovenian}{loadhyph-sl.tex}{}{2}{2}
TEX_HYPHEN_DEF+=	\addlanguage{slovene}{loadhyph-sl.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['slovenian']={ \
			\\tloader='loadhyph-sl.tex', \
			\\tlefthyphenmin=2, \
			\\trighthyphenmin=2, \
			\\tsynonyms={'slovene',}, \
			\\tpatterns='hyph-sl.pat.txt', \
			\\thyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
