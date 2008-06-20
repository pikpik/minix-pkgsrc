# $NetBSD: Makefile,v 1.14 2008/04/10 12:01:16 drochner Exp $
#

GST_PLUGINS0.10_NAME=	gnomevfs
GST_PLUGINS0.10_DIRS=	ext/gnomevfs
GST_PLUGINS0.10_FLAGS=	gnome_vfs

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-base/Makefile.common"

.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
