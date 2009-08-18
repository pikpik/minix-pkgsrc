# $NetBSD: Makefile,v 1.3 2009/07/22 09:01:44 wiz Exp $

DISTNAME=	memhangul-ucs-1.4.4f
PKGNAME=	tex-${DISTNAME}
CATEGORIES=	print
MASTER_SITES=	http://my.ktug.or.kr/~karnes/testtest/
EXTRACT_SUFX=	.zip

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://faq.ktug.or.kr/faq/MemhangulClass
COMMENT=	Korean support in memoir

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	tex-dhucs>=2.6:../../print/tex-dhucs
DEPENDS+=	tex-memoir>=1.618:../../print/tex-memoir

NO_CONFIGURE=	yes
NO_BUILD=	yes

.include "../../print/teTeX/module.mk"

INSTALLATION_DIRS=	${PKG_LOCALTEXMFPREFIX}/doc/latex/memhangul \
			${PKG_LOCALTEXMFPREFIX}/tex/latex/memhangul \
			${PKG_LOCALTEXMFPREFIX}/fonts/cmap \
			${PKG_LOCALTEXMFPREFIX}/makeindex/

do-install:
.for f in appendixtest.tex doeun.bb doeun.png memucstest.tex
	${INSTALL_DATA} ${WRKSRC}/doc/memhangul-ucs/${f} \
		${DESTDIR}${PKG_LOCALTEXMFPREFIX}/doc/latex/memhangul
.endfor
	${INSTALL_DATA} ${WRKSRC}/fonts/cmap/UTF8-UCS2 \
		${DESTDIR}${PKG_LOCALTEXMFPREFIX}/fonts/cmap/
	${INSTALL_DATA} ${WRKSRC}/makeindex/memucs-manual.ist \
		${DESTDIR}${PKG_LOCALTEXMFPREFIX}/makeindex/
	${INSTALL_DATA} ${WRKSRC}/tex/latex/memhangul/*.sty \
		${DESTDIR}${PKG_LOCALTEXMFPREFIX}/tex/latex/memhangul/

.include "../../mk/bsd.pkg.mk"
