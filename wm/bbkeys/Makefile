# $NetBSD: Makefile,v 1.15 2005/06/01 18:03:24 jlam Exp $
#

DISTNAME=	bbkeys-0.8.6
CATEGORIES=	x11 wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bbkeys/}

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://bbkeys.sourceforge.net/
COMMENT=	General X Window keygrabber

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c++
USE_TOOLS+=	perl:run

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
