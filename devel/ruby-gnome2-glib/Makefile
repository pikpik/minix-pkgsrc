# $NetBSD: Makefile,v 1.2 2006/02/05 23:08:52 joerg Exp $
#

PKGNAME=		ruby-gnome2-glib-${VERSION}
COMMENT=		Ruby binding of GLib-2.x
CATEGORIES=		devel

RUBY_EXTCONF_SUBDIRS=	glib

USE_TOOLS+=		pkg-config

.include "../../devel/glib2/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
