# $NetBSD$

DISTNAME=	surfaw-0.5.4-1
PKGNAME=	surfaw-0.5.4
CATEGORIES=	www
MASTER_SITES=	http://download.sourceforge.net/surfaw/

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://surfaw.sourceforge.net/

WRKSRC=		${WRKDIR}/${PKGNAME}

GNU_CONFIGURE=	# defined

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/surfaw
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/surfaw

.include "../../mk/bsd.pkg.mk"
