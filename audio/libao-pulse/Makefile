# $NetBSD: Makefile,v 1.12 2007/11/30 17:50:33 wiz Exp $

.include "../../audio/libao/Makefile.common"

PKGNAME=	${DISTNAME:S/libao/libao-pulse/}

COMMENT+=	(pulse plugin)

CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/disable-pulse/enable-pulse/g}
BUILD_DIRS=		${WRKSRC}/src/plugins/pulse
INSTALL_DIRS=		${WRKSRC}/src/plugins/pulse

_LIBAO_BUILDING_PLUGIN=	yes

.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../audio/libao/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
