# $NetBSD: Makefile,v 1.2 2005/04/11 21:45:37 tv Exp $
#

DISTNAME=	pthread-sem-1.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.cit.gu.edu.au/teaching/2105CIT/software/

MAINTAINER=	rh@NetBSD.org
COMMENT=	Semaphore implementation for (PTH) pthreads

PTHREAD_OPTS+=	require

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
