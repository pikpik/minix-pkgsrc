# $NetBSD$

DISTNAME=	hands-2.0.bsd386
PKGNAME=	bridge-hands-2.0
CATEGORIES=	games
MASTER_SITES=	http://www.whiteoaks.com/hands/

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.whiteoaks.com/hands/
COMMENT=	generate hands for duplicate bridge

EXTRACT_ELEMENTS=	hands/source
WRKSRC=			${WRKDIR}/hands/source

USE_BUILDLINK_ONLY=	YES

do-build:
	cd ${WRKSRC} && \
		${CC} ${CFLAGS} ${CPPFLAGS} ${LDFLAGS} -o hands hands.c ${LIBS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hands ${PREFIX}/bin/bridge-hands

.include "../../mk/bsd.pkg.mk"
