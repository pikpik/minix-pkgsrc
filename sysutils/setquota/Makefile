# $NetBSD: Makefile,v 1.12 2008/06/20 01:09:36 joerg Exp $
#

DISTNAME=	setquota-0.1
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.jurai.net/users/winter/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	# unknown
COMMENT=	Command line quota tools

PKG_DESTDIR_SUPPORT=	user-destdir

# BSD oriented, haven't checked on other environment now
ONLY_FOR_PLATFORM=	NetBSD-*-* DragonFly-*-*

WRKSRC=		${WRKDIR}/setquota/

INSTALLATION_DIRS=	${PKGMANDIR}/cat8 ${PKGMANDIR}/man8 sbin
USE_BSD_MAKEFILE=	yes

.include "../../mk/bsd.pkg.mk"
