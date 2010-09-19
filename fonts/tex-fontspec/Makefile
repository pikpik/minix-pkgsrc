# $NetBSD: Makefile,v 1.2 2010/05/19 23:09:15 minskim Exp $

DISTNAME=	fontspec
PKGNAME=	tex-${DISTNAME}-2.1
TEXLIVE_REV=	19796

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Advanced font selection in XeLaTeX and LuaLaTeX

DEPENDS+=	tex-ifxetex-[0-9]*:../../print/tex-ifxetex
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
