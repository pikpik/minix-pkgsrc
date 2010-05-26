# $NetBSD: Makefile,v 1.2 2009/07/10 23:38:31 minskim Exp $

DISTNAME=	memoir
PKGNAME=	tex-${DISTNAME}-1.618033988c.6.0f
TEXLIVE_REV=	17927

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Typeset fiction, non-fiction and mathematical books

CONFLICTS+=	teTeX-texmf<=3.0nb17
DEPENDS+=	tex-ifxetex-[0-9]*:../../print/tex-ifxetex
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
