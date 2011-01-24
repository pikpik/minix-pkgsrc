# $NetBSD: Makefile,v 1.3 2010/11/13 16:45:44 minskim Exp $

DISTNAME=	amsrefs
PKGNAME=	tex-${DISTNAME}-2.09
PKGREVISION=	1
TEXLIVE_REV=	20249

MAINTAINER=	minskim@NetBSD.org
COMMENT=	LaTeX-based replacement for BibTeX

CONFLICTS+=	tex-ams-[0-9]*
DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
DEPENDS+=	tex-url>=3.2:../../print/tex-url

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
