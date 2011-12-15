# $NetBSD: Makefile,v 1.1.1.1 2010/06/16 23:58:11 minskim Exp $

DISTNAME=	metapost.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-1.212
TEXLIVE_REV=	23089

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-metapost

CONFLICTS+=	teTeX-texmf<=3.0nb25

TEX_TEXMF_DIRS+=		${PREFIX}/share/texmf-dist
TEXLIVE_IGNORE_PATTERNS=	texmf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
