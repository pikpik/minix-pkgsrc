# $NetBSD: Makefile,v 1.1.1.1 2002/04/08 20:00:56 schmonz Exp $
#

.include "../ce/Makefile.common"

PKGNAME=		ce-x11-${VERSION}
COMMENT+=		, X11 version

USE_BUILDLINK_ONLY=	# defined

ALL_TARGET=		xce
INSTALL_TARGET=		install-x11 man-install-x11

.include "../../devel/ncurses/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
