# $NetBSD: Makefile,v 1.1.1.1 2009/04/23 23:50:11 minskim Exp $
# TeX Live Revision 9734

DISTNAME=	exam
PKGNAME=	tex-${DISTNAME}-2.3
PKGREVISION=	1

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Package for typesetting exam scripts

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
