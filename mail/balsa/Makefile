# $NetBSD: Makefile,v 1.4 2000/06/01 11:23:34 rh Exp $
#

DISTNAME=	balsa-0.9.0
CATEGORIES=	mail gnome
MASTER_SITES=	ftp://ftp.newton.cx/pub/balsa/ \
		http://www.theochem.kth.se/~pawsa/balsa/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.balsa.net/

DEPENDS+=	pth-*:../../devel/pth
DEPENDS+=	libproplist-*:../../devel/libproplist
DEPENDS+=	gnome-core-*:../../x11/gnome-core

GNU_CONFIGURE=	yes
USE_X11BASE=	yes
USE_PKGLIBTOOL=	yes
LTCONFIG_OVERRIDE=${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
