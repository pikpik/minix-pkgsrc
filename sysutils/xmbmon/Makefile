# $NetBSD$
#

.include "../../sysutils/mbmon/Makefile.common"

PKGNAME=	xmbmon-201

COMMENT=	X11-based motherboard monitoring utility

USE_X11=	yes
USE_BUILDLINK2=	yes

ALL_TARGET=	xmbmon

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmbmon ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
