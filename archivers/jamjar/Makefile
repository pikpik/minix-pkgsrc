# $NetBSD$
#

DISTNAME=	jamjar-0.6
CATEGORIES=	archivers
MASTER_SITES=	ftp://wonka.acunia.com/pub/wonka/

MAINTAINER=	skrll@netbsd.org
HOMEPAGE=	http://wonka.acunia.com/
COMMENT=	Acunia version of the jar archiver.

BUILD_DEPENDS+=	acunia-jam>=1.0:../../devel/acunia-jam

WRKSRC=		${WRKDIR}/jamjar

CFLAGS+=	-Wall

do-build:
	cd ${WRKSRC} && \
		 ${PREFIX}/bin/jam \
			-sPREFIX="${PREFIX}" \
			-sCFLAGS="${CFLAGS}"

do-install:
	cd ${WRKSRC} && \
		 ${PREFIX}/bin/jam \
			-sPREFIX="${PREFIX}" \
			-sCFLAGS="${CFLAGS}" install 

.include "../../mk/bsd.pkg.mk"
