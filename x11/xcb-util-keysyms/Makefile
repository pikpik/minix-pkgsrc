# $NetBSD: Makefile,v 1.2 2012/10/02 12:09:41 tron Exp $
#

DISTNAME=	xcb-util-keysyms-0.3.9
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://xcb.freedesktop.org/dist/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xcb.freedesktop.org/
COMMENT=	XCB Utilities
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	xcb-keysyms.pc.in

.include "../../x11/libxcb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
