# $NetBSD: Makefile,v 1.5 2006/06/14 11:23:17 drochner Exp $
#

.include "Makefile.common"

COMMENT+=		good plugins

CONFIGURE_ARGS+=	--enable-gconf
CONFIGURE_ARGS+=	--enable-gconftool
CONFIGURE_ARGS+=	--enable-zlib

# We depend on libxml anyway (indirectly through GConf2), so this
# doesn't hurt. Just make it explicite.
CONFIGURE_ARGS+=	--enable-annodex
.include "../../textproc/libxml2/buildlink3.mk"

GCONF2_SCHEMAS=		gstreamer-0.10.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
