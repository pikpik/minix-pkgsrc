# $NetBSD: Makefile,v 1.3 2009/05/02 16:21:43 reed Exp $
#

DISTNAME=	libmowgli-0.7.1
CATEGORIES=	devel
MASTER_SITES=	http://distfiles.atheme.org/ \
		http://mirror.billymays.us/libmowgli/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://www.atheme.org/projects/mowgli
COMMENT=	Development framework for C (like GLib)

PKG_DESTDIR_SUPPORT=	user-destdir

PREV_PKGPATH=	devel/mowgli

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libmowgli.pc.in

.include "../../mk/bsd.pkg.mk"
