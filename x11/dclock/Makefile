# $NetBSD$

DISTNAME=	dclock
PKGNAME=	dclock-pl4
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:S/contrib/R5contrib/}
EXTRACT_SUFX=	.shar.Z

MAINTAINER=	packages@netbsd.org

USE_X11BASE=	yes
EXTRACT_CMD=	${GZCAT} ${DOWNLOADED_DISTFILE} | ${SH} -
WRKSRC=		${WRKDIR}

.include "../../mk/bsd.pkg.mk"
