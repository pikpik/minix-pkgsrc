# $NetBSD: Makefile,v 1.1.1.1 2009/07/21 07:24:30 minskim Exp $

DISTNAME=	fontspec
PKGNAME=	tex-${DISTNAME}-1.18
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Automatic interface to feature-rich fonts in XeLaTeX

DEPENDS+=	tex-ifxetex-[0-9]*:../../print/tex-ifxetex
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
