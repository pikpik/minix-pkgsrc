# $NetBSD: Makefile,v 1.3 2003/07/17 22:51:58 grant Exp $
#

DISTNAME=	udptunnel-1.1
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.cs.columbia.edu/pub/lennox/udptunnel/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.cs.columbia.edu/~lennox/udptunnel/
COMMENT=	Tunnel UDP packets over a TCP connection

GNU_CONFIGURE=		YES
INSTALLATION_DIRS=	bin share/doc/html

post-install:
	${INSTALL_DATA} ${WRKSRC}/udptunnel.html ${PREFIX}/share/doc/html/

.include "../../mk/bsd.pkg.mk"
