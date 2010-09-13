# $NetBSD: Makefile,v 1.1.1.1 2010/05/10 22:42:51 minskim Exp $

DISTNAME=	cmcyr.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2009
TEXLIVE_REV=	16696
DIST_SUBDIR=	${PKGBASE}-${TEXLIVE_REV}.2010

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-cmcyr

CONFLICTS+=	teTeX-texmf<=3.0nb24

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
