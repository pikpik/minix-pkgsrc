# $NetBSD: Makefile,v 1.1.1.1 2009/08/02 19:17:51 minskim Exp $

DISTNAME=	fancyvrb
PKGNAME=	tex-${DISTNAME}-2.7a
PKGREVISION=	1
TEXLIVE_REV=	16609

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Sophisticated verbatim text

CONFLICTS+=	teTeX-texmf<=3.0nb20
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
