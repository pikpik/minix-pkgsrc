# $NetBSD: Makefile,v 1.6 2001/03/22 13:53:58 wiz Exp $

DISTNAME=	aspell-gaeilge-2.0
CATEGORIES=	textproc
MASTER_SITES=   http://borel.slu.edu/~kps/ispell/

MAINTAINER=	jschauma@netbsd.org
HOMEPAGE=	http://borel.slu.edu/~kps/ispell/
COMMENT=	Irish language support for aspell

DEPENDS+=	aspell>=0.33.7.1:../../textproc/aspell

ASPELLDATA=${PREFIX}/share/aspell/

do-install:
	${INSTALL_DATA} ${WRKSRC}/gaeilge.dat ${ASPELLDATA}
	${INSTALL_DATA} ${WRKSRC}/gaeilge_phonet.dat ${ASPELLDATA}
	${INSTALL_DATA} ${WRKSRC}/gaeilge ${PREFIX}/lib/aspell

.include "../../mk/bsd.pkg.mk"
