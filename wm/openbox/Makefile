# $NetBSD: $
#

DISTNAME=	openbox-2.2.0
CATEGORIES=	wm
MASTER_SITES=	http://icculus.org/openbox/releases/

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://icculus.org/openbox/
COMMENT=	Window manager based on Blackbox

DEPENDS+=	bsetroot>=0.1:../../wm/bsetroot

USE_X11=	YES
GNU_CONFIGURE=	YES

WRKSRC=		${WRKDIR}/openbox-2.2.0

.include "../../graphics/freetype2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
