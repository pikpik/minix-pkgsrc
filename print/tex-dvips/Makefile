# $NetBSD: Makefile,v 1.1.1.1 2009/06/07 05:52:23 minskim Exp $
# TeX Live Revision 16376

DISTNAME=	dvips
PKGNAME=	tex-${DISTNAME}-2009.16376

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Files for a DVI to PostScript driver

CONFLICTS+=	teTeX-texmf<=3.0nb15
CONFLICTS+=	tex-bin-dvipsk<=2008.12898

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf
TEXLIVE_IGNORE_PATTERNS=	texmf/dvips/base

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
