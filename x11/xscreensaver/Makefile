# $NetBSD: Makefile,v 1.47 2002/02/09 21:12:56 wiz Exp $
#

COMMENT=	Screen saver and locker for the X window system

CONFLICTS+=	xscreensaver-gnome-[0-9]*

USE_BUILDLINK_ONLY=	yes

.include "../../x11/xscreensaver/Makefile.common"

CONFIGURE_ARGS+=	--without-gnome
CONFIGURE_ARGS+=	--with-configdir=${PREFIX}/libexec/xscreensaver/config

.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
