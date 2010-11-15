# $NetBSD: Makefile,v 1.3 2010/09/24 17:04:07 minskim Exp $

DISTNAME=	ukrhyph
PKGNAME=	tex-${DISTNAME}-2009
PKGREVISION=	1
TEXLIVE_REV=	18396

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation pattern files for Ukrainian

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-ruhyphen>=1.6:../../print/tex-ruhyphen

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
