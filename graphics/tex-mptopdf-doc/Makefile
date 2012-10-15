# $NetBSD: Makefile,v 1.1.1.1 2011/01/20 17:08:16 minskim Exp $

DISTNAME=	mptopdf.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2012
TEXLIVE_REV=	26689

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-mptopdf

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
