# $NetBSD: Makefile,v 1.3 2000/07/11 21:22:06 tron Exp $

DISTNAME=		pppoe.20000912
PKGNAME=		mouse_${DISTNAME:S/./-/}
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.netbsd.org/pub/NetBSD/misc/mouse/pppoe/

MAINTAINER=		mouse@netbsd.org

CONFLICTS+=		rp-pppoe-*

NO_WRKSUBDIR=		yes

do-build:
	(cd ${WRKSRC} ; ${CC} -O2 -o pppoe pppoe.c)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pppoe ${PREFIX}/sbin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mouse_pppoe
	${INSTALL_DATA} ${WRKSRC}/pppoe.readme ${PREFIX}/share/doc/mouse_pppoe

.include "../../mk/bsd.pkg.mk"
