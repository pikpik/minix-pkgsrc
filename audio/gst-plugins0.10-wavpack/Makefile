# $NetBSD: Makefile,v 1.5 2011/05/18 09:49:01 drochner Exp $
#

GST_PLUGINS0.10_NAME=	wavpack
GST_PLUGINS0.10_DIRS=	ext/wavpack

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-good/Makefile.common"

PKGREVISION=		1

.include "../../audio/wavpack/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
