# $NetBSD$
#

GST_PLUGINS_NAME=	opengl
GST_PLUGINS_DIR=	sys/glsink

.include "../../multimedia/gst-plugins/Makefile.common"

BUILDLINK_DEPENDS.gst-plugins+=	gst-plugins>=0.8.7nb1

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
