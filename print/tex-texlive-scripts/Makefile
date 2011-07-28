# $NetBSD: Makefile,v 1.8 2011/03/10 19:51:06 minskim Exp $

DISTNAME=	texlive-scripts
PKGNAME=	tex-${DISTNAME}-2011
TEXLIVE_REV=	23172

MAINTAINER=	minskim@NetBSD.org
COMMENT=	TeX Live infrastructure programs
LICENSE=	gnu-gpl-v2 AND public-domain

CONFLICTS+=	tex-bin-texlive-[0-9]*

REPLACE_TEXLUA=		bin/rungs \
			texmf/scripts/texlive/lua/texlive/getopt.tlu \
			texmf/scripts/texlive/lua/texlive/tlpdb.tlu \
			texmf/scripts/texlive/test-tlpdb.tlu \
			texmf/scripts/texlive/texconf.tlu
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf/scripts/texlive/rungs.tlu ${WRKSRC}/bin/rungs

.include "../../mk/bsd.pkg.mk"
