# $NetBSD: Makefile,v 1.11 2007/01/16 23:27:48 joerg Exp $
#

.include "../../x11/wxGTK28/Makefile.common"

PKGNAME=		${DISTNAME:S/wxGTK/wxGTK28-contrib/}
MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		GTK-based implementation of the wxWidgets GUI library (contrib libraries)

USE_TOOLS+=		gmake

BUILD_DIRS=		contrib/src

INSTALL_TARGET=		install

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
