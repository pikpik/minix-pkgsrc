# $NetBSD: Makefile,v 1.5 2003/07/21 16:49:45 martti Exp $

DISTNAME=	fortune-strfile-0
CATEGORIES=	games
DISTFILES=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Tool to prepare a fortune database

WRKSRC=		${WRKDIR}
NO_CHECKSUM=	yes

# we depend on the "make" infrastructure
ONLY_FOR_PLATFORM= NetBSD-*

do-extract:
	${CP} ${FILESDIR}/strfile.* ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
