# $NetBSD: Makefile,v 1.16 2000/06/01 11:23:40 rh Exp $
#

DISTNAME=	ggv-0.95
CATEGORIES=	print gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=stable/sources/ggv/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnome.org/

DEPENDS+=	ghostscript-[6-9]*:../../print/ghostscript
DEPENDS+=	gnome-core>=1.2.0:../../x11/gnome-core

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_X11BASE=	YES

.include "../../mk/bsd.pkg.mk"
