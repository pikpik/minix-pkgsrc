# $NetBSD$
#

.include "Makefile.common"

CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/--disable-oss/--enable-oss/}
CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/--disable-vorbis/--enable-vorbis/}

.include "../../audio/libogg/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
