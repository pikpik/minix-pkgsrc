# $NetBSD: Makefile,v 1.4 2009/04/11 18:49:18 minskim Exp $
# TeX Live Revision 12298

DISTNAME=	bin-tetex
PKGNAME=	tex-${DISTNAME}-3.0.12298

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Supplementary files for updmap

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

TEXLIVE_IGNORE_PATTERNS=	texmf/web2c/updmap.cfg

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
