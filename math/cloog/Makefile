# $NetBSD: Makefile,v 1.3 2012/09/11 23:04:17 asau Exp $

DISTNAME=	cloog-0.18.0
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU:=gcc/infrastructure/}

MAINTAINER=	kuehro@gmx.de
HOMEPAGE=	http://www.cloog.org/
COMMENT=	Code generator for loop optimization (used by gcc)
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

TEST_TARGET=	check

CONFIGURE_ARGS+=	--with-isl=system
CONFIGURE_ARGS+=	--with-bits=gmp

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/isl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
