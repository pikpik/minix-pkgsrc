# $NetBSD$

.include "${.CURDIR}/../gftp/Makefile.common"

PKGNAME=	gftp-gtk1-${VERSION}
COMMENT=	Multithreaded GTK+ ftp client

DEPENDS+=	gnome1-dirs>=1.0:../../misc/gnome1-dirs
CONFLICTS=	gftp-[0-9]*

CONFIGURE_ARGS+=	--disable-gtk20

PLIST_SRC=	${.CURDIR}/../gftp/PLIST
DISTINFO_FILE=	${.CURDIR}/../gftp/distinfo

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
