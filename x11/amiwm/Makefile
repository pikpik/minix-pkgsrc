# $NetBSD: Makefile,v 1.2 1998/04/15 10:38:52 agc Exp $
#

DISTNAME=	amiwm0.20pl48
PKGNAME=	amiwm-0.20pl48
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/X11/wm/amiwm/

MAINTAINER=	rh@trapdoor.vip.at

USE_X11=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="-DHAVE_X11_EXTENSIONS_SHAPE_H=1 -O"

MAN1=		amiwm.1

.include "../../mk/bsd.pkg.mk"
