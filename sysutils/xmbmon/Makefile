# $NetBSD: Makefile,v 1.10 2006/02/05 23:10:58 joerg Exp $
#

.include "../../sysutils/mbmon/Makefile.common"

PKGNAME=	xmbmon-205
PKGREVISION=	1

COMMENT=	X11-based motherboard monitoring utility


BUILD_TARGET=	xmbmon

LDFLAGS+=	-Wl,-R${X11BASE}/lib

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmbmon ${PREFIX}/bin

.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
