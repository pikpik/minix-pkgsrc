# $NetBSD: Makefile,v 1.4 2001/06/26 09:54:07 zuntum Exp $
#

DISTNAME=	SDL_ttf-2.0.3
CATEGORIES=	devel
MASTER_SITES=	http://www.libsdl.org/projects/SDL_ttf/release/

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://www.libsdl.org/projects/SDL_ttf/
COMMENT=	use TrueType fonts in your SDL applications

USE_BUILDLINK_ONLY=	YES
USE_CONFIG_WRAPPER=	YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../devel/SDL/buildlink.mk"
.include "../../graphics/freetype2/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
