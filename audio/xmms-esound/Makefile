# $NetBSD$
#

.include "../../audio/xmms/Makefile.common"

PKGNAME=	${DISTNAME:S/xmms/xmms-esound/}
CATEGORIES+=	gnome

COMMENT=	XMMS plugin to output sound through the esound daemon

CONFLICTS+=	xmms<=1.2.7nb8

BUILDLINK_DEPENDS.xmms=	xmms>=1.2.7nb9

BUILD_DIRS=	${WRKSRC}/Output/esd
INSTALL_DIRS=	${WRKSRC}/Output/esd

.include "../../audio/esound/buildlink2.mk"
.include "../../audio/xmms/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
