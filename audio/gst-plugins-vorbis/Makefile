# $NetBSD$
#

GST_PLUGINS_NAME=	vorbis
GST_PLUGINS_DIR=	ext/vorbis

.include "../../multimedia/gst-plugins/Makefile.common"

DEPENDS+=		gst-plugins-ogg>=0.8.0:../../audio/gst-plugins-ogg

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
