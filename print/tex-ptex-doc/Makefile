# $NetBSD: Makefile,v 1.2 2011/02/07 19:59:44 minskim Exp $

DISTNAME=	ptex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-3.2
TEXLIVE_REV=	25342

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-ptex

TEXLIVE_IGNORE_PATTERNS=	texmf/doc/man

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
