# $NetBSD: Makefile,v 1.10 2004/05/07 01:14:46 xtraeme Exp $

DISTNAME=	openal-20040816
CATEGORIES=	audio
MASTER_SITES=	http://math.smsu.edu/~erik/files/fbsd/ \
		http://www.smluc.org/~erik/ \
		http://csc.smsu.edu/~greenwald/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.openal.org/
COMMENT=	3D positional spatialized sound library

WRKSRC=			${WRKDIR}/${DISTNAME}/linux
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

USE_MAKEINFO=	yes
INFO_FILES=	openal.info

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/openal.info ${PREFIX}/info

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
