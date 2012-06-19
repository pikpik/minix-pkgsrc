# $NetBSD$
#

PKGNAME=	dde-linux26-usb-drivers-21
DISTNAME=	dde-linux26-usb-drivers-21
MASTER_SITES=   http://www.minix3.org/distfiles-minix/
CATEGORIES=	minix
PKGREVISION=    # empty

MAINTAINER=	Kees Jongenburger
HOMEPAGE=	http://minix3.org/
COMMENT=	DDE/linux2.6 based usb drivers
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=   destdir
INSTALLATION_DIRS= sbin etc/system.conf.d etc/rc.d etc/devmand

USE_LANGUAGES=	c
USE_TOOLS+= bmake
MAKE_ENV+=  NOGCCERROR=yes

.include "../../mk/bsd.prefs.mk"
.include "../../minix/dde-linux26/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
