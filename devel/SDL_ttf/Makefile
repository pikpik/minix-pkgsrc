# $NetBSD: Makefile,v 1.13 2003/07/26 21:41:11 jmmv Exp $
#

DISTNAME=	SDL_ttf-2.0.3
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://www.libsdl.org/projects/SDL_ttf/release/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://www.libsdl.org/projects/SDL_ttf/
COMMENT=	Use TrueType fonts in your SDL applications

USE_BUILDLINK3=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
