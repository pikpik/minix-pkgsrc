# $NetBSD: Makefile,v 1.28 2012/09/15 10:05:48 obache Exp $
#

.include "Makefile.common"

COMMENT+=		good plugins

CONFIGURE_ARGS+=	--enable-zlib

PKGCONFIG_OVERRIDE+=	pkgconfig/*.pc.in

# only useful if gstreamer was built with the "gstcheck" option
TEST_TARGET=		check-torture

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
