# $NetBSD: Makefile,v 1.5 1999/02/20 22:48:27 hubertf Exp $
#

DISTNAME=	hexedit-1.1.0
WRKSRC=		${WRKDIR}/hexedit
CATEGORIES=	editors
MASTER_SITES=	http://www.chez.com/prigaux/
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.chez.com/prigaux/hexedit.html

DEPENDS+=	ncurses-4.2:../../devel/ncurses

GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib	# for -lncurses

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/hexedit
.for file in COPYING Changes TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/hexedit
.endfor

.include "../../mk/bsd.pkg.mk"
