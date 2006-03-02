# $NetBSD: Makefile,v 1.2 2005/06/16 06:57:56 jlam Exp $

DISTNAME=	gpsd-2.31
CATEGORIES=	geography
MASTER_SITES=	http://download.berlios.de/gpsd/

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://www.pygps.org/gpsd/
COMMENT=	GPS information daemon

GNU_CONFIGURE=	YES
USE_LIBTOOL=	yes

INSTALLATION_DIRS=	sbin

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
