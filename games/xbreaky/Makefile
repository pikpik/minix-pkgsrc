# $NetBSD: Makefile,v 1.3 2001/02/16 15:11:01 wiz Exp $
#

DISTNAME=	xbreaky-0.0.4
CATEGORIES=	games
MASTER_SITES=	http://xbreaky.sourceforge.net/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://xbreaky.sourceforge.net/
COMMENT=	breakout game for X11

USE_BUILDLINK_ONLY=	YES
USE_X11BASE=		YES

.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/ossaudio.buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
