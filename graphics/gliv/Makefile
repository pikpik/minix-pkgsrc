# $NetBSD: Makefile,v 1.15 2006/02/15 17:49:32 drochner Exp $

DISTNAME=	gliv-1.9.4
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://guichaz.free.fr/gliv/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://guichaz.free.fr/gliv/
COMMENT=	OpenGL image viewer

BUILD_USES_MSGFMT=	yes

USE_DIRS+=		xdg-1.1
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/gliv.png ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/gliv.desktop \
		${PREFIX}/share/applications/gnome-gliv.desktop

.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/gtkglext/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
