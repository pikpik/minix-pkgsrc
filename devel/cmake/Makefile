# $NetBSD$
#

DISTNAME=	cmake-1.6.6
CATEGORIES=	devel
MASTER_SITES=	http://www.cmake.org/files/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.cmake.org
COMMENT=	cross platform make

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_GMAKE=	YES
USE_NCURSES=	YES

post-patch:
	${MV} ${WRKSRC}/Modules/FindCurses.cmake ${WRKSRC}/Modules/FindCurses.cmake.bak
	${SED} 's;@prefix@;${PREFIX};g' ${WRKSRC}/Modules/FindCurses.cmake.bak > \
		${WRKSRC}/Modules/FindCurses.cmake

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
