# $NetBSD: Makefile,v 1.4 2004/01/07 18:00:16 jlam Exp $
#

USE_BUILDLINK3=	yes

.include "../libao/Makefile.common"

PKGNAME=	${DISTNAME:S/libao/libao-esound/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT+=	(esound plugin)

CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/disable-esd/enable-esd/g}
BUILD_DIRS=		${WRKSRC}/src/plugins/esd
INSTALL_DIRS=		${WRKSRC}/src/plugins/esd

.include "../../audio/esound/buildlink3.mk"
.include "../../audio/libao/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
