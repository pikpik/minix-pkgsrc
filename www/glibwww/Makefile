# $NetBSD: Makefile,v 1.2 2001/02/17 17:22:04 wiz Exp $
#

DISTNAME=		glibwww-0.2
CATEGORIES=		www gnome devel
MASTER_SITES=		${MASTER_SITE_GNOME:=unstable/sources/glibwww/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		event register functions that use the glib event loop

BUILDLINK_DEPENDS.gnome-libs=	gnome-libs>=1.2.3
BUILDLINK_DEPENDS.libwww=	libwww>=5.2.8

USE_BUILDLINK_ONLY=	YES

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../www/libwww/buildlink.mk"
.include "../../x11/gnome-libs/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
