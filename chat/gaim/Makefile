# $NetBSD: Makefile,v 1.18 2002/07/01 17:16:20 hubertf Exp $
#

.include "Makefile.common"

CONFIGURE_ARGS+=	--disable-gnome
CONFIGURE_ARGS+=	--disable-panel

PLIST_SRC+=    ${.CURDIR}/../gaim/PLIST

CONFLICTS+=	gaim-gnome-[0-9]*

.include "../../audio/esound/buildlink.mk"
.include "../../graphics/gdk-pixbuf/buildlink.mk"
.include "../../lang/perl5/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
