# $NetBSD: Makefile,v 1.3 2010/09/19 23:20:33 minskim Exp $

DISTNAME=	tools
PKGNAME=	tex-${DISTNAME}-2010
TEXLIVE_REV=	20258

MAINTAINER=	minskim@NetBSD.org
COMMENT=	The LaTeX standard tools bundle

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-graphics>=1.0onb1:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
