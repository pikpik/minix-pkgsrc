# $NetBSD: Makefile,v 1.3 2000/12/15 01:38:29 wiz Exp $
#

DISTNAME=       gnofin-0.8.4
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnofin/}

MAINTAINER=	mellon@isc.org
HOMEPAGE=	http://gnofin.sourceforge.net/

BUILD_DEPENDS+=	msgfmt:../../devel/gettext
DEPENDS+=	gtk+-1.2.*:../../x11/gtk
DEPENDS+=	gnome-libs-*:../../x11/gnome-libs

USE_X11=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LIBINTL=	yes
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
