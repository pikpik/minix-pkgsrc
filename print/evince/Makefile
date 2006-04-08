# $NetBSD: Makefile,v 1.13 2006/03/30 21:30:42 jmmv Exp $
#

.include "../../print/evince/Makefile.common"

COMMENT=		Document viewer for the GNOME Desktop

GCONF2_SCHEMAS=		evince.schemas
GCONF2_SCHEMAS+=	evince-thumbnailer.schemas

.include "../../security/gnome-keyring/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
