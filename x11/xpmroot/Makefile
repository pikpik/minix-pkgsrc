# $NetBSD: Makefile,v 1.15 2001/05/31 09:11:00 dent Exp $
#

DISTNAME=       fvwm-${PKG_VERSION}
PKGNAME=	xpmroot-${PKG_VERSION}
PKG_VERSION=	2.2.5
CATEGORIES=	x11
MASTER_SITES=   ftp://ftp.hpc.uh.edu/pub/fvwm/version-2/ \
		ftp://ftp.ics.es.osaka-u.ac.jp/pub/CFAN/sources/2.0.x/ \
		ftp://ftp.ics.es.osaka-u.ac.jp/pub/CFAN/fvwm-users-jp/kits/ \
		ftp://ftp.TokyoNet.AD.JP/pub/X/fvwm/sources/2.0.x/ \
		ftp://ftp.TokyoNet.AD.JP/pub/X/fvwm/fvwm-users-jp/kits/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.fvwm.org/generated/manpages/xpmroot.html
COMMENT=	Sets the root window to an Xpm pixmap

USE_BUILDLINK_ONLY=	YES
USE_X11BASE=	YES
WRKSRC=		${WRKDIR}/${DISTNAME}/utils

MAKE_ENV+=	INSTALL_PROGRAM='${INSTALL_PROGRAM}'
MAKE_ENV+=	INSTALL_MAN='${INSTALL_MAN}'
MAKE_ENV+=	VERSION=${PKG_VERSION}

.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
