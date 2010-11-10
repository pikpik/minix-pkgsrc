# $NetBSD: Makefile,v 1.3 2010/11/08 16:59:16 minskim Exp $

DISTNAME=	hyphen-hungarian
PKGNAME=	tex-${DISTNAME}-2010
PKGREVISION=	1
TEXLIVE_REV=	20144

MAINTAINER=	minskim@NetBSD.org
COMMENT=	New Hungarian hyphenation patterns

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	hungarian loadhyph-hu.tex
TEX_HYPHEN_DEF+=	\addlanguage{hungarian}{loadhyph-hu.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['hungarian']={ \
			  loader='loadhyph-hu.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={}, \
			  patterns='hyph-hu.pat.txt', \
			  hyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
