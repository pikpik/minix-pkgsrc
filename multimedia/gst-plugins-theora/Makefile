# $NetBSD: Makefile,v 1.1.1.1 2004/04/06 13:51:43 jmmv Exp $
#

GST_PLUGINS_NAME=	theora
GST_PLUGINS_DIR=	ext/theora

PKGREVISION=		1

.include "../../multimedia/gst-plugins/Makefile.common"

DEPENDS+=		gst-plugins-ogg>=0.8.1:../../multimedia/gst-plugins-ogg

.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
