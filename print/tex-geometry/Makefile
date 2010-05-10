# $NetBSD: Makefile,v 1.1.1.1 2009/07/12 03:32:45 minskim Exp $

DISTNAME=	geometry
PKGNAME=	tex-${DISTNAME}-5.3
TEXLIVE_REV=	17466

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Flexible and complete interface to document dimensions

CONFLICTS+=	teTeX-texmf<=3.0nb18
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
