# $NetBSD: Makefile,v 1.4 2008/11/23 13:45:33 jmcneill Exp $
#

GNOME_VFS_NAME=		dns-sd
GNOME_VFS_FLAG=		avahi
CATEGORIES=		net

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS+=	${EGDIR}/modules

.include "../../sysutils/gnome-vfs/Makefile.common"

.include "../../net/avahi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
