# $NetBSD: Makefile,v 1.1.1.1 2001/05/30 14:30:48 agc Exp $
#

DISTNAME=	qvwm-1.1.11
CATEGORIES=	wm
MASTER_SITES=	ftp://www.qvwm.org/pub/qvwm/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.qvwm.org/
COMMENT=	Windows 95/98/NT like window manager for X11

USE_X11BASE=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

post-install:
	${MV} ${PREFIX}/man/man1/qvwm.1x ${PREFIX}/man/man1/qvwm.1

.include "../../audio/esound/buildlink.mk"
.include "../../graphics/imlib/buildlink.mk"
.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
