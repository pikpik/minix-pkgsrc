# $NetBSD: Makefile,v 1.26 2004/01/03 18:49:55 reed Exp $
#

PKGNAME=	links-gui-2.1.0.14
PKGREVISION=	1

COMMENT=	Lynx-like text and graphics WWW browser

CONFLICTS+=	links-[0-9]* elinks-0.3*

USE_X11=	YES

CONFIGURE_ARGS+=	--enable-graphics

.include "../../www/links/Makefile.common"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
