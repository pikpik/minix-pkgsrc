# $NetBSD$
#

DISTNAME=	randread-0.1
CATEGORIES=	benchmarks
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=randread/}

MAINTAINER=	grant@netbsd.org
HOMEPAGE=	http://randread.sourceforge.net/
COMMENT=	program to help benchmark random disk read performance

WRKSRC=		${WRKDIR}

ALL_TARGET=	randread

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/randread ${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
