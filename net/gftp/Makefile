# $NetBSD: Makefile,v 1.19 2004/04/05 02:45:45 xtraeme Exp $
#

.include "${.CURDIR}/Makefile.common"

COMMENT=	Multithreaded GTK2+ ftp client

CONFLICTS=	gftp-gtk1-[0-9]*

USE_DIRS+=	gnome2-1.5

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
