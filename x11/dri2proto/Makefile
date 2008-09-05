# $NetBSD$
#

DISTNAME=	dri2proto-1.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=proto/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Modular X.org DRI2 headers

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	# none

PKGCONFIG_OVERRIDE+=	dri2proto.pc.in

.include "../../mk/bsd.pkg.mk"
