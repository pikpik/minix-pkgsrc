# $NetBSD$
# TeX Live Revision 10592

DISTNAME=	luatex
PKGNAME=	tex-${DISTNAME}-0.1

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.luatex.org/
COMMENT=	LuaTeX basic definition package

DEPENDS+=	tex-etex-[0-9]*:../../print/tex-etex
DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex
DEPENDS+=	web2c-[0-9]*:../../print/web2c

TEX_FORMAT_NAMES+=	luatex
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
