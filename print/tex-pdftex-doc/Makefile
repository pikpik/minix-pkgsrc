# $NetBSD: Makefile,v 1.10 2011/12/14 19:42:15 minskim Exp $

DISTNAME=	pdftex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-1.40.11pl27932
TEXLIVE_REV=	27932

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-pdftex

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

TEXLIVE_IGNORE_PATTERNS=	texmf/doc/man/man1/pdftex.1

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
