# $NetBSD: Makefile,v 1.5 2006/07/25 16:49:05 minskim Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-pango-${VERSION}
COMMENT=		Ruby binding of pango-1.x
CATEGORIES=		devel fonts

CONFLICTS+=		ruby-gnome2-pango-[0-9]*

RUBY_EXTCONF_SUBDIRS=	pango

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-glib>=${VERSION}:../../devel/ruby-gnome2-glib

USE_TOOLS+=		pkg-config

INSTALL_TARGET=		install

.include "../../devel/pango/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
