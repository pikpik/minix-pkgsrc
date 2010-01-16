# $NetBSD$
# TeX Live Revision 16483

DISTNAME=	texlive-scripts
PKGNAME=	tex-${DISTNAME}-2009.16483

MAINTAINER=	minskim@NetBSD.org
COMMENT=	TeX Live infrastructure programs
LICENSE=	gnu-gpl-v2 AND public-domain

CONFLICTS+=	tex-bin-texlive-[0-9]*

REPLACE_TEXLUA=		bin/rungs
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf/scripts/texlive/rungs.tlu ${WRKSRC}/bin/rungs

.include "../../mk/bsd.pkg.mk"
