# $NetBSD: Makefile,v 1.3 2006/04/06 06:22:25 reed Exp $

.include "../../multimedia/libdv/Makefile.common"

PKGNAME=		${DISTNAME:S/-/-tools-/}

COMMENT+=		(standalone tools)

USE_TOOLS+=		pkg-config

CONFIGURE_ARGS+=	--enable-gtk

BUILD_DIRS=		encodedv playdv
INSTALL_DIRS=		encodedv playdv

BUILDLINK_API_DEPENDS.libdv+=	libdv>=1.0.0

.include "../../devel/glib/buildlink3.mk"
.include "../../multimedia/libdv/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
