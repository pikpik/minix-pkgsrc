# $NetBSD$
#

DISTNAME=	unzoo.c
PKGNAME=	unzoo-4.4
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.math.rwth-aachen.de/pub/gap/gap4/util/
EXTRACT_SUFX=	# defined

MAINTAINER=	cjep@netbsd.org
COMMENT=	Extract zoo archives

WRKSRC=		${WRKDIR}
USE_BUILDLINK2=	YES

do-extract:
	${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}

do-build:
	cd ${WRKSRC} &&	${CC} ${CFLAGS} -DSYS_IS_UNIX -DSYS_HAS_MKDIR -o unzoo unzoo.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unzoo ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
