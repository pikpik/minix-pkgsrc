# $NetBSD: Makefile,v 1.10 2012/09/15 10:03:38 obache Exp $
#

GST_PLUGINS1_NAME=	mad
GST_PLUGINS1_DIRS=	ext/mad

.include "../../multimedia/gst-plugins1-ugly/Makefile.common"

CONFIGURE_ARGS+=	--enable-mad

.include "../../audio/libmad/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
