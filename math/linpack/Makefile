# $NetBSD: Makefile,v 1.1.1.1 2001/04/27 22:57:30 jtb Exp $

DISTNAME=	linpack-20010427
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	packages@netbsd.org
COMMENT=	Library of linear algebra Fortran routines

DEPENDS+=	blas-[0-9]*:../../math/blas

NO_SRC_ON_FTP=	Already in MASTER_SITE_LOCAL
WRKSRC=		${WRKDIR}/linpack
USE_FORTRAN=	yes

.include "../../mk/bsd.pkg.mk"
