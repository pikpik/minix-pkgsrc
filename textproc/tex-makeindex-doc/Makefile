# $NetBSD: Makefile,v 1.2 2010/02/14 22:29:49 minskim Exp $

DISTNAME=	makeindex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2.12
PKGREVISION=	1
TEXLIVE_REV=	18835

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-makeindex

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

TEXLIVE_IGNORE_PATTERNS=	texmf/doc/man

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
