# $NetBSD$

DISTNAME=	pthread-stublib-1.0
CATEGORIES=	devel
DISTFILES=	# empty

MAINTAINER=	drochner@NetBSD.org
COMMENT=	Library providing noop-stubs for pthread functions

WRKSRC=		${WRKDIR}
NO_CHECKSUM=	yes
USE_LIBTOOL=	yes

ONLY_FOR_PLATFORM= NetBSD-[12].*-*

do-extract:
	${CP} ${FILESDIR}/pthread-stubs.c ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
