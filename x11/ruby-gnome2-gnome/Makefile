# $NetBSD: Makefile,v 1.13 2008/03/06 14:53:57 wiz Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-gnome-${VERSION}
CATEGORIES=		gnome x11
COMMENT=		Ruby binding of libgnome/libgnomeui-2.x

CONFLICTS+=		ruby-gnome2-gnome-[0-9]*

RUBY_EXTCONF_SUBDIRS=	glib gnome

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-gnomecanvas>=${VERSION}:../../graphics/ruby-gnome2-gnomecanvas

USE_TOOLS+=		pkg-config

.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
