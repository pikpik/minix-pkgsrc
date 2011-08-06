# $NetBSD: Makefile,v 1.4 2011/05/18 09:49:02 drochner Exp $
#

GST_PLUGINS0.10_NAME=	v4l2
GST_PLUGINS0.10_DIRS=	sys/v4l2
GST_PLUGINS0.10_FLAGS=	gst_v4l2

PKG_DESTDIR_SUPPORT=	user-destdir

ONLY_FOR_PLATFORM=	NetBSD-[5-9]* Linux-*

.include "../../multimedia/gst-plugins0.10-good/Makefile.common"

PKGREVISION=		1

CONFIGURE_ARGS+= --with-libv4l2

.include "../../graphics/libv4l/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
