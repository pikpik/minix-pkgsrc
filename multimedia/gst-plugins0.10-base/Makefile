# $NetBSD: Makefile,v 1.5 2006/05/10 16:42:39 drochner Exp $
#

.include "Makefile.common"

COMMENT+=		base plugins

USE_TOOLS+=		perl:run

PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-plugins-base-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-plugins-base.pc.in

REPLACE_PERL+=		tools/gst-visualise-m.m

# only useful if gstreamer was built with the "gstcheck" option
TEST_TARGET=		check-torture

.include "../../mk/bsd.pkg.mk"
