# $NetBSD: Makefile,v 1.2 2010/05/10 07:06:44 minskim Exp $

DISTNAME=	txfonts
PKGNAME=	tex-${DISTNAME}-2009
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Times-like fonts in support of mathematics

CONFLICTS+=	teTeX-texmf<=3.0nb19

TEX_MAP_FILES+=	txfonts.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
