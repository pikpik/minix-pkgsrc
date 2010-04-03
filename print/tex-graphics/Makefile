# $NetBSD: Makefile,v 1.2 2010/01/29 09:00:43 minskim Exp $
# TeX Live Revision 17600

DISTNAME=	graphics
PKGNAME=	tex-${DISTNAME}-1.0o
DIST_SUBDIR=	${PKGNAME_NOREV}-17600
PKGREVISION=	1

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Standard LaTeX graphics

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-pdftex-def-[0-9]*:../../print/tex-pdftex-def

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
