# $NetBSD: Makefile,v 1.7 2002/07/11 14:24:01 abs Exp $
#

.include "../libflash/Makefile.common"

PKGNAME=	${DISTNAME:C/-/player-/}
PKGREVISION=	2
COMMENT=	standalone open source Flash(tm) player

USE_BUILDLINK2=	yes
BUILD_DIRS=	${WRKSRC}/Player
CPPFLAGS+=	-DDEV_DSP=\\\"${DEVOSSSOUND}\\\"

.include "../libflash/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
