# $NetBSD: Makefile,v 1.3 2009/08/29 15:31:55 wiz Exp $
#

DISTNAME=		xf86bigfontproto-1.2.0
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=proto/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		XF86BigFont extension headers from X.org

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	xf86bigfontproto.pc.in
USE_LANGUAGES=		# empty

.include "../../mk/bsd.pkg.mk"
