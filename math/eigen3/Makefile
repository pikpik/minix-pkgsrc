# $NetBSD: Makefile,v 1.9 2012/09/11 23:04:18 asau Exp $

DISTNAME=	3.1.2
PKGNAME=	eigen3-3.1.2
CATEGORIES=	math
MASTER_SITES=   http://bitbucket.org/eigen/eigen/get/
DIST_SUBDIR=	eigen3
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://eigen.tuxfamily.org/
COMMENT=	C++ template library for linear algebra
LICENSE=	mpl-2.0

USE_LANGUAGES+= c c++
USE_CMAKE= yes
CMAKE_ARG_PATH= ..
CONFIGURE_DIRS= _build
WRKSRC=		${WRKDIR}/eigen-eigen-5097c01bcdc4
FETCH_USING=	curl

pre-configure:
	${MKDIR} ${WRKSRC}/_build

.include "../../mk/bsd.pkg.mk"
