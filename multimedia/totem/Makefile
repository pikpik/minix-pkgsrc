# $NetBSD$
#

.include "Makefile.common"

COMMENT+=	(using GStreamer)

CONFLICTS+=	totem-xine-[0-9]*

BUILDLINK_DEPENDS.gstreamer+=	gstreamer>=0.8.6.1

.include "../../multimedia/gst-plugins/buildlink3.mk"
.include "../../multimedia/gstreamer/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
