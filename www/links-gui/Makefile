# $NetBSD: Makefile,v 1.9 2002/05/10 08:14:35 wiz Exp $
#

PKGNAME=	links-gui-2.0
COMMENT=	Lynx-like text and graphics WWW browser

CONFLICTS+=	links-[0-9]*

CONFIGURE_ARGS+=	--enable-graphics

.include "../../graphics/png/buildlink.mk"
.include "../../graphics/tiff/buildlink.mk"
.include "../../www/links/Makefile.common"
