# $NetBSD: Makefile,v 1.5 2009/04/27 14:32:07 minskim Exp $
# TeX Live Revision 12871

DISTNAME=	bin-kpathsea
PKGNAME=	tex-${DISTNAME}-2008.12871

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Translation tables for TeX

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

TEXLIVE_IGNORE_PATTERNS=	texmf/web2c/fmtutil.cnf \
				texmf/web2c/mktex.opt \
				texmf/web2c/mktex[a-z]* \
				texmf/web2c/texmf.cnf

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
