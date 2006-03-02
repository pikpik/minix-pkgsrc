# $NetBSD: Makefile,v 1.6 2006/01/03 20:48:01 joerg Exp $
#

DISTNAME=		mpfr-2.2.0
CATEGORIES=		math
MASTER_SITES=		http://www.mpfr.org/mpfr-current/

DIST_SUBDIR=		mpfr-2.2.0-060221
PATCH_SITES=		http://www.mpfr.org/mpfr-current/
PATCHFILES=		patches
PATCH_DIST_STRIP=	-p1

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.mpfr.org/
COMMENT=		GMP-based library for multiple-precision floating-point computations

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
TEST_TARGET=		check
INFO_FILES=		mpfr.info

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
