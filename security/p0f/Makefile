# $NetBSD$
#

DISTNAME=	p0f-1.7
CATEGORIES=	security
MASTER_SITES=	http://lcamtuf.hack.pl/
EXTRACT_SUFX=	.tgz

MAINTAINER=	DawS@irc.pl
COMMENT=	passive OS fingerprinting tool

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/p0f ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/p0f.fp ${PREFIX}/etc

.include "../../mk/bsd.pkg.mk"
