# $NetBSD$
#

DISTNAME=	xchiplogo
PKGNAME=	xchiplogo-19991222
CATEGORIES=	cad
MASTER_SITES=	http://www.eleceng.adelaide.edu.au/Personal/moini/

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://www.eleceng.adelaide.edu.au/Personal/moini/chiplogo.html

DEPENDS+=	xforms-*:../../x11/xforms
DEPENDS+=	xpm-*:../../graphics/xpm

USE_X11=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xchiplogo ${LOCALBASE}/bin/xchiplogo

.include "../../mk/bsd.pkg.mk"
