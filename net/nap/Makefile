# $NetBSD$

DISTNAME=	nap-1.4.3
CATEGORIES=	net
MASTER_SITES=	http://download.sourceforge.net/nap/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.gis.net/~nite/

DEPENDS+=	ncurses>=5.0:../../devel/ncurses

GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	CPPFLAGS=-I${LOCALBASE}/include

post-install:
	${MKDIR} ${PREFIX}/share/doc/nap ${PREFIX}/share/examples/nap
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/nap
	${INSTALL_DATA} ${WRKSRC}/nap.conf.dist \
	  ${PREFIX}/share/examples/nap/nap.conf

.include "../../mk/bsd.pkg.mk"
