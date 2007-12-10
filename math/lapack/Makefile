# $NetBSD: Makefile,v 1.22 2007/12/02 11:20:53 wiz Exp $

DISTNAME=	lapack-lite-3.1.1
PKGNAME=	lapack-3.1.1
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.netlib.org/lapack/			\
		ftp://netlib.no/netlib/lapack/			\
		ftp://ftp.zib.de/netlib/lapack/
EXTRACT_SUFX=	.tgz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.netlib.org/lapack/index.html
COMMENT=	Linear Algebra PACKage

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c fortran
USE_LIBTOOL=		YES
BUILD_TARGET=		lapacklib

INSTALLATION_DIRS=	lib

do-install:
	${LIBTOOL} --mode=install ${INSTALL_DATA} ${WRKSRC}/liblapack.la \
		${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
