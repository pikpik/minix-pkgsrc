# $NetBSD: Makefile,v 1.10 2006/05/18 19:55:35 wiz Exp $

DISTNAME=	easydiskpasswd-1.0
PKGREVISION=	1
CATEGORIES=	sysutils
DISTFILES=	# empty

MAINTAINER=	drochner@NetBSD.org
COMMENT=	Tool to unlock a password protected USB "EasyDisk"

NO_CHECKSUM=	yes
WRKSRC=		${WRKDIR}
MAKE_ENV+=	BINOWN=${BINOWN} BINGRP=${BINGRP}

# we depend on SCIOCCOMMAND, a header defining sense codes
# and the "make" infrastructure
ONLY_FOR_PLATFORM= NetBSD-[3-9]*-*

do-extract:
	${CP} ${FILESDIR}/easydiskpasswd.c ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
