# $NetBSD: Makefile,v 1.1.1.1 2002/12/26 19:55:01 tsarna Exp $

DISTNAME=	gpsd-1.07
CATEGORIES=	misc
MASTER_SITES=	http://www.pygps.org/gpsd/

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.pygps.org/gpsd/
COMMENT=	GPS information daemon

GNU_CONFIGURE=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gpsd /usr/pkg/sbin

.include "../../mk/bsd.pkg.mk"
