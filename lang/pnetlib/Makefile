# $NetBSD: Makefile,v 1.9 2006/12/15 20:32:58 joerg Exp $
#

PKGREVISION=		3

.include "Makefile.common"

# Disable xft support for now, it's broken.
#CONFIGURE_ARGS+=	--enable-xft
CONFIGURE_ARGS+=	--with-x

CONFLICTS=		pnetlib-nox11-[0-9]*

BUILDLINK_DEPMETHOD.libXt?=	build

#.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
