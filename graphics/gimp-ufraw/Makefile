# $NetBSD$
#

DISTNAME=		ufraw-0.3
PKGNAME=		gimp-ufraw-0.3
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ufraw/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://ufraw.sourceforge.net/
COMMENT=		GIMP plug-in for raw digicam import

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
BUILD_TARGET=		build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ufraw-gimp \
		${PREFIX}/lib/gimp/2.0/plug-ins

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../graphics/gimp/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
