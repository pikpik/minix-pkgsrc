# $NetBSD: Makefile,v 1.5 2007/02/22 19:01:28 wiz Exp $
#

DISTNAME=		xrestop-0.4
CATEGORIES=		x11
MASTER_SITES=		http://projects.o-hand.com/sources/xrestop/

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.freedesktop.org/wiki/Software/xrestop
COMMENT=		X11 clients' server-side resource usage monitor

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../devel/ncurses/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXres/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
