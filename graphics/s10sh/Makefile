# $NetBSD$
#

DISTNAME=	s10sh-0.2.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.kyuzz.org/antirez/s10sh-src/

MAINTAINER=	drochner@netbsd.org
HOMEPAGE=	http://www.kyuzz.org/antirez/s10sh
COMMENT=	USB/serial userspace driver for Canon PowerShot cameras

DEPENDS+=	libusb-*:../../devel/libusb

HAS_CONFIGURE=	yes

do-install:
	${INSTALL} ${WRKSRC}/s10sh ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
