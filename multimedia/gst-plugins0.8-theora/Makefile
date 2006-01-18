# $NetBSD: Makefile,v 1.4 2005/12/31 12:32:43 wiz Exp $
#

GST_PLUGINS0.8_NAME=	theora
GST_PLUGINS0.8_DIR=	ext/theora

.include "../../multimedia/gst-plugins0.8/Makefile.common"

DEPENDS+=		gst-plugins0.8-ogg>=0.8.1:../../multimedia/gst-plugins0.8-ogg

.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
