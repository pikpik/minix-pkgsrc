# $NetBSD: Makefile,v 1.23 2012/10/03 21:56:49 wiz Exp $
#
.include "Makefile.common"

#CONFIGURE_ARGS+= --disable-silent-rules

COMMENT+=		base plugins

USE_TOOLS+=		perl:run

PKGCONFIG_OVERRIDE+=	pkgconfig/*.pc.in

REPLACE_PERL+=		tools/gst-visualise-m.m

# only useful if gstreamer was built with the "gstcheck" option
TEST_TARGET=		check-torture

# soft dependency only, .pc file not needed
#.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
