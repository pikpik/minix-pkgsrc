# $NetBSD: Makefile,v 1.19 2004/01/07 02:21:16 jlam Exp $
#

.include "Makefile.common"

PKGNAME=		${DISTNAME:S/-/2-/}
PKGREVISION=		4

CONFIGURE_ARGS+=	--disable-pixbuf-loader

.include "../../graphics/freetype2/buildlink2.mk"
.include "../../graphics/libart2/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/libgsf/buildlink2.mk"
.include "../../devel/pango/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../textproc/libcroco/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
