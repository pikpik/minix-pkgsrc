# $NetBSD: Makefile,v 1.2 2010/04/21 05:58:05 minskim Exp $

DISTNAME=	koma-script
PKGNAME=	tex-${DISTNAME}-3.06
TEXLIVE_REV=	19027

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Bundle of versatile classes and packages

CONFLICTS+=	teTeX-texmf<=3.0nb17
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
