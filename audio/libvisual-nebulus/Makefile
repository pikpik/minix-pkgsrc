# $NetBSD$
#

DISTNAME=		libvisual-nebulus-0.1.4
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=libvisual/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://libvisual.sourceforge.net/
COMMENT=		Nebulus plugin for libvisual

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes

.include "../../audio/libvisual/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
