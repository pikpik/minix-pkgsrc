# $NetBSD: Makefile,v 1.1 2002/06/20 16:28:18 agc Exp $
#

DISTNAME=	arirang-1.6
PKGNAME=	arirang-1.6
CATEGORIES=	security www
MASTER_SITES=	http://www.monkey.org/~pilot/arirang/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.monkey.org/~pilot/arirang/
COMMENT=	Powerful webserver security scanner

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/arirang ${PREFIX}/sbin
	${INSTALL_DATA_DIR} ${PREFIX}/share/arirang/
	${INSTALL_DATA} ${WRKSRC}/scanrule/*.uxe ${PREFIX}/share/arirang

.include "../../mk/bsd.pkg.mk"
