# $NetBSD: Makefile,v 1.1.1.1 2001/04/17 21:48:31 rh Exp $
#

DISTNAME=	fire-1.0
CATEGORIES=	games
MASTER_SITES=	http://www.libsdl.org/projects/fire/src/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.libsdl.org/projects/fire/index.html
COMMENT=	organic fireworks demo

USE_BUILDLINK_ONLY=	YES
USE_CONFIG_WRAPPER=	YES
GNU_CONFIGURE=		YES
USE_X11=		YES

.include "../../devel/SDL/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
