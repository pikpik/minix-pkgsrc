# $NetBSD: Makefile,v 1.1.1.1 2010/04/12 21:20:48 minskim Exp $

DISTNAME=	hyphen-greek.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-5
TEXLIVE_REV=	20144

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-hyphen-greek

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
