# $NetBSD: Makefile,v 1.3 2002/08/16 03:12:14 jschauma Exp $

DISTNAME=	aspell-gaeilge-2.0
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=   http://borel.slu.edu/~kps/ispell/

MAINTAINER=	jschauma@netbsd.org
HOMEPAGE=	http://borel.slu.edu/~kps/ispell/
COMMENT=	Irish language support for aspell

ASPELLDATA=	${PREFIX}/share/aspell/

do-install:
	${INSTALL_DATA} ${WRKSRC}/gaeilge.dat ${ASPELLDATA}
	${INSTALL_DATA} ${WRKSRC}/gaeilge_phonet.dat ${ASPELLDATA}
	${INSTALL_DATA} ${WRKSRC}/gaeilge ${PREFIX}/lib/aspell

.include "../../textproc/aspell/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
