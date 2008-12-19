# $NetBSD: Makefile,v 1.8 2008/01/18 14:40:19 itohy Exp $

DISTNAME=		kyopon-0.5
CATEGORIES=		comms
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		itohy@NetBSD.org
#HOMEPAGE=
COMMENT=		tool to manipulate data of Kyocera PHS handset

PKG_DESTDIR_SUPPORT=	user-destdir

ONLY_FOR_PLATFORM=	NetBSD-*-* DragonFly-*-*

USE_BSD_MAKEFILE=	yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat1 ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
