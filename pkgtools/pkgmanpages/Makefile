# $NetBSD: Makefile,v 1.1.1.1 1999/12/07 11:44:04 agc Exp $
#

DISTNAME=	pkgmanpages-19991222
CATEGORIES=	pkgtools
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	agc@netbsd.org
HOMEPAGE=	http://www.netbsd.org/

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
PREFIX=		/usr/share
.endif

do-install:
	${BSD_INSTALL_MAN} ${WRKSRC}/packages.7 ${PREFIX}/man/man7

.include "../../mk/bsd.pkg.mk"
