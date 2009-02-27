# $NetBSD$
#

DISTNAME=	multisync-gui-0.91.0
CATEGORIES=	comms
MASTER_SITES=	http://www.opensync.org/attachment/wiki/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.opensync.org/
COMMENT=	GUI for libopensync

USE_DIRS+=	xdg-1.1
HAS_CONFIGURE=	yes

REPLACE_PYTHON= waf

.include "../../lang/python/application.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../comms/libopensync/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
