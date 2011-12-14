# $NetBSD: Makefile,v 1.6 2011/03/03 23:13:20 minskim Exp $

DISTNAME=	luatex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-0.70.1
TEXLIVE_REV=	23398

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.luatex.org/
COMMENT=	Documentation for tex-luatex

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
