# $NetBSD: Makefile,v 1.13 2004/07/24 10:33:12 wiz Exp $
#

DISTNAME=	chicken-1.66
CATEGORIES=	lang
MASTER_SITES=	http://www.call-with-current-continuation.org/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.call-with-current-continuation.org/chicken.html
COMMENT=	Scheme to C compiler, handling R5RS

GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes
USE_LIBTOOL=	yes
TEST_TARGET=	test

INFO_FILES=	chicken.info

# Avoid an ICE in gcc2 on sparc64
CONFIGURE_ENV+=	F77=${FALSE}

# This is for the test target
UNLIMIT_RESOURCES=	datasize

.include "../../mk/bsd.pkg.mk"
