# $NetBSD: Makefile,v 1.1.1.1 2000/02/19 22:32:44 rh Exp $
#

DISTNAME=	plib-1.0.20
CATEGORIES=	games x11
MASTER_SITES=	http://plib.sourceforge.net/dist/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://plib.sourceforge.net/

DEPENDS+=	Mesa-*:../../graphics/Mesa

USE_X11=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"
CPPFLAGS+=	-Dunix=1 -I${X11PREFIX}/include -I${X11BASE}/include

.include "../../mk/bsd.pkg.mk"
