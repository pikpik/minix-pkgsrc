# $NetBSD$
PKGNAME=	dde-linux26-20
DISTNAME=	dde-linux26-20
MASTER_SITES=   http://www.minix3.org/distfiles-minix/
CATEGORIES=	minix
PKGREVISION=    # empty


MAINTAINER=	Kees Jongenburger
HOMEPAGE=	http://minix3.org/
COMMENT=	DDE/Linux26 is an environment for Linux 2.6 device drivers
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT= destdir
INSTALLATION_DIRS= include lib

USE_LANGUAGES=	c
USE_TOOLS+= perl
MAKE_ENV+=  NOGCCERROR=yes

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
