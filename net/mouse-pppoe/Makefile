# $NetBSD: Makefile,v 1.2 2000/02/08 23:46:14 hubertf Exp $

DISTNAME=		mouse_pppoe
PKGNAME=		${DISTNAME}-20000202
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.styx.org/pub/mouse_pppoe/

MAINTAINER=		mouse@netbsd.org

CONFLICTS+=		rp-pppoe-*

DIST_SUBDIR=		${PKGNAME}
WRKSRC=			${WRKDIR}/${DISTNAME}

do-build:
	(cd ${WRKSRC} ; ${CC} -O2 -o pppoe pppoe.c)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pppoe ${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
