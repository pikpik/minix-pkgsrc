# $NetBSD: Makefile,v 1.4 2001/04/30 04:16:10 jlam Exp $
#
# todo: set location of [md-]whois.conf and fix in man page too
# todo: build and install the po/ files and add to PLIST
# todo: add choice for mk/bsd.pkg.defaults.mk to define name prefix
# (defaults to "md-" to distinguish from other whois clients) and adjust PLIST

VERSION=	4.6.3
DISTNAME=	whois_${VERSION}
PKGNAME=	md-whois-${VERSION}
CATEGORIES=	net
MASTER_SITES=	http://www.linux.it/~md/software/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.linux.it/~md/software/
COMMENT=	Improved whois client

USE_PERL5=	build

WRKSRC=		${WRKDIR}/whois-${VERSION}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/whois ${PREFIX}/bin/md-whois
	${INSTALL_MAN} ${WRKSRC}/whois.1 ${PREFIX}/man/man1/md-whois.1

.include "../../mk/bsd.pkg.mk"
