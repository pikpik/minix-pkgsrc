# $NetBSD: Makefile,v 1.2 2008/11/24 12:50:17 wiz Exp $
#

GST_PLUGINS0.10_NAME=	hal
GST_PLUGINS0.10_DIRS=	ext/hal
GST_PLUGINS0.10_FLAGS=	hal

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-good/Makefile.common"

.include "../../sysutils/hal/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
