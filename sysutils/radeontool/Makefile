# $NetBSD: Makefile,v 1.27 2004/11/09 12:30:40 adam Exp $

DISTNAME=	radeontool-1.5
CATEGORIES=	sysutils
MASTER_SITES=	http://fdd.com/software/radeon/

MAINTAINER=	jmcneill@NetBSD.org
HOMEPAGE=	http://fdd.com/software/radeon/
COMMENT=	Toggle backlight and external video output on Radeon cards

USE_BUILDLINK3=		yes
BUILD_TARGET=		radeontool

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/radeontool ${PREFIX}/sbin

.include "../../sysutils/pciutils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
