# $NetBSD: Makefile,v 1.9 1998/06/22 12:39:48 agc Exp $
#

DISTNAME=       xpm-3.4k
CATEGORIES=	graphics x11
MASTER_SITES=	ftp://avahi.inria.fr/pub/xpm/

MAINTAINER=	mycroft@netbsd.org

CONFLICTS=	xpm-3.4j

USE_IMAKE=	yes

post-install:
	${LDCONFIG} || ${TRUE}

.include "../../mk/bsd.pkg.mk"
