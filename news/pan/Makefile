# $NetBSD$
#

DISTNAME=		pan-0.9.6
CATEGORIES=		news gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/pan/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://pan.rebelbase.com/
COMMENT=		Newsreader for Gnome

DEPENDS+=		gnome-core>1.4.0:../../x11/gnome-core
BUILD_USES_MSGFMT=	YES

USE_X11BASE=		YES
USE_LIBINTL=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		LOCALEDIR="${PKGLOCALEDIR}"
CPPFLAGS+=		-D_POSIX_THREAD_SYSCALL_SOFT=1

.include "../../mk/bsd.pkg.mk"
