# $NetBSD: Makefile,v 1.12 2003/01/30 17:57:45 salo Exp $
#

DISTNAME=	sodipodi-0.31
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sodipodi/}

MAINTAINER=	manu@netbsd.org
HOMEPAGE=	http://www.gnome.org/gnome-office/sodipodi.shtml
COMMENT=	Open source vector graphics drawing program using SVG as native format

DEPENDS+=	gnome2-dirs>=1.0:../../misc/gnome2-dirs

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
USE_X11BASE=		YES

LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

.include "../../graphics/libart2/buildlink2.mk"
.include "../../print/libgnomeprintui/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
