# $NetBSD: Makefile,v 1.7 2008/01/18 05:06:36 tnn Exp $
#

DISTNAME=	wormux-0.8
CATEGORIES=	games
MASTER_SITES=	http://download.gna.org/wormux/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.wormux.org/
COMMENT=	Battle game

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_PKGLOCALEDIR= yes
USE_TOOLS+=	pkg-config msgfmt
USE_DIRS+=	xdg-1.1

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../devel/SDL_gfx/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"
.include "../../textproc/libxml++/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
