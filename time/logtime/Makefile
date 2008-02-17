# $NetBSD: Makefile,v 1.9 2006/03/11 11:12:34 kim Exp $
#

DISTNAME=		logtime-1.2
CATEGORIES=		sysutils time
MASTER_SITES=		ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us
COMMENT=		Prints date and time in a standard format

NO_CONFIGURE=		yes

MAKE_FLAGS+=		PREFIX=${PREFIX}

BUILD_TARGET=		all
INSTALL_TARGET=		install
INSTALLATION_DIRS=	${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
