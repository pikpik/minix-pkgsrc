# $NetBSD$
#

DISTNAME=	bmp-mac-0.1.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mac-port/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/mac-port/
COMMENT=	BMP plugin for Monkey's Audio files

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c++

.include "../../audio/bmp/buildlink3.mk"
.include "../../audio/mac/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
