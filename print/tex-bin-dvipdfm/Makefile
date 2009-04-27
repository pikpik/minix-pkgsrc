# $NetBSD: Makefile,v 1.2 2009/04/13 00:13:03 minskim Exp $
# TeX Live Revision 12785

DISTNAME=	bin-dvipdfm
PKGNAME=	tex-${DISTNAME}-0.13.2d.12785

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Supplementary files for dvipdfm

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

TEXLIVE_IGNORE_PATTERNS=	texmf/fonts

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
