# $NetBSD$
#

DISTNAME=	novawm-0.7_alpha
PKGNAME=	${DISTNAME:S/_alpha/rc1/}
WRKSRC=		${WRKDIR}/${DISTNAME:S/_alpha//}
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=novawm/}

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://novawm.sourceforge.net/
COMMENT=	Nova window manager

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_GMAKE=	YES
USE_X11=	YES

.include "../../mk/bsd.pkg.mk"
