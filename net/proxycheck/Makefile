# $NetBSD$
#

DISTNAME=	proxycheck-0.41
CATEGORIES=	net
MASTER_SITES=	http://www.corpit.ru/mjt/proxycheck/

MAINTAINER=	tv@pobox.com
HOMEPAGE=	http://www.corpit.ru/mjt/proxycheck.html
COMMENT=	Tester for open (promiscuous) proxy systems

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/proxycheck ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/proxycheck.1 ${PREFIX}/man/man1/

.include "../../mk/bsd.pkg.mk"
