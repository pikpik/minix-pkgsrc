# $NetBSD: Makefile,v 1.2 1999/06/04 15:39:09 drochner Exp $
#

DISTNAME=	vipec-1.07
CATEGORIES=	cad
MASTER_SITES=	http://netfold.com/~vipec/public_ftp/unstable/

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://www.netfold.com/~vipec/

DEPENDS+=	qt1-1.44:../../x11/qt1

USE_X11=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vipec ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/vipec
	${INSTALL_DATA} ${WRKSRC}/ckt/*.ckt ${PREFIX}/share/examples/vipec
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/vipec
	${INSTALL_DATA} ${WRKSRC}/help/* ${PREFIX}/share/doc/vipec

.include "../../mk/bsd.pkg.mk"
