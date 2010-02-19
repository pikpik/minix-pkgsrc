# $NetBSD: Makefile,v 1.1.1.1 2009/04/27 18:00:24 minskim Exp $
# TeX Live Revision 12056

DISTNAME=	natbib
PKGNAME=	tex-${DISTNAME}-8.3
PKGREVISION=	1

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Flexible bibliography support for BibTeX

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	web2c-[0-9]*:../../print/web2c

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
