# $NetBSD: Makefile,v 1.2 2010/05/06 20:42:03 minskim Exp $

DISTNAME=	enumitem
PKGNAME=	tex-${DISTNAME}-2.2
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Control layout of itemize, enumerate, and description

CONFLICTS+=	teTeX-texmf<=3.0nb17
DEPENDS+=	tex-graphics>=1.0onb1:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
