# $NetBSD$

DISTNAME=	tkpiechart-5.3
CATEGORIES=	graphics
MASTER_SITES=	http://www.multimania.com/jfontain/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.mygale.org/~jfontain/

DEPENDS+=	tk-8.0.5:../../x11/tk80
DEPENDS+=	stooop-3.7:../../devel/stooop

NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${PREFIX}/lib/tkpiechart
	cd ${WRKSRC}; ./instapkg.tcl ${PREFIX}/lib/tkpiechart

.include "../../mk/bsd.pkg.mk"
