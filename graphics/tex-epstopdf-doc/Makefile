# $NetBSD$

DISTNAME=	epstopdf.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2.16
TEXLIVE_REV=	19287

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-epstopdf

CONFLICTS=	texlive-pdftools<2011

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
