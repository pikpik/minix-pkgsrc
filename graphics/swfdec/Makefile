# $NetBSD: Makefile,v 1.12 2004/01/22 12:48:32 jmmv Exp $
#

.include "Makefile.common"

PKGREVISION=		7

CONFIGURE_ARGS+=	--disable-pixbuf-loader

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
