# $NetBSD: Makefile,v 1.2 2001/02/02 00:23:52 jtb Exp $

DISTNAME=		minpack-20001130
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		jtb@netbsd.org
COMMENT=		FORTRAN 77 library for the solution of nonlinear equations

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL
WRKSRC=			${WRKDIR}/minpack
USE_FORTRAN=		YES

pre-build:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"