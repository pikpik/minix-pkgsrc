# $NetBSD: Makefile,v 1.8 1999/09/08 19:27:16 tron Exp $
#

DISTNAME=	gnome-print-0.9
CATEGORIES=	print gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-print/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.levien.com/gnome/print-arch.html

DEPENDS+=	gnome-libs-1.0.16:../../x11/gnome-libs
DEPENDS+=	libxml-1.*:../../textproc/libxml
DEPENDS+=	ghostscript-*:../../print/ghostscript5

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_X11BASE=	YES
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include"

.include "../../mk/bsd.pkg.mk"
