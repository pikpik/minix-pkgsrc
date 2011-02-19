# $NetBSD: Makefile,v 1.37 2011/01/13 13:39:46 wiz Exp $

DISTNAME=		gtk-engines-0.12
PKGREVISION=		14
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gtk-engines/0.12/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Theme engines for GTK+

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=		gtk2-engines-*

GNU_CONFIGURE=		yes
USE_X11BASE=		yes
USE_LIBTOOL=		yes
SHLIBTOOL_OVERRIDE=	# empty

.include "../../x11/gtk/buildlink3.mk"
.include "../../graphics/imlib-gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
