# $NetBSD$
#

COMMENT=	Enlightened Canvas Library

.include "Makefile.common"

CONFIGURE_ARGS+=	--enable-font-loader-eet

PKGCONFIG_OVERRIDE=	evas.pc.in

INSTALLATION_DIRS=	lib/evas/modules/loaders lib/evas/modules/savers

.include "../../devel/eet/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
