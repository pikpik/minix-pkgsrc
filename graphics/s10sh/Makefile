# $NetBSD: Makefile,v 1.2 2001/09/27 23:18:13 jlam Exp $
#

DISTNAME=	s10sh-0.2.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.kyuzz.org/antirez/s10sh-src/

MAINTAINER=	drochner@netbsd.org
HOMEPAGE=	http://www.kyuzz.org/antirez/s10sh
COMMENT=	USB/serial userspace driver for Canon PowerShot cameras

HAS_CONFIGURE=	yes
CONFIGURE_ENV+=	LOCALBASE=${LOCALBASE}

do-install:
	${INSTALL} ${WRKSRC}/s10sh ${PREFIX}/bin

.include "../../devel/libusb/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
