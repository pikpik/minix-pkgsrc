# $NetBSD: Makefile,v 1.2 1999/04/15 20:39:47 tron Exp $
#

DISTNAME=		psmisc-19
CATEGORIES=		sysutils
MASTER_SITES=		ftp://lrcftp.epfl.ch/pub/linux/local/psmisc/ \
			${MASTER_SITE_SUNSITE:=system/status/ps/}

MAINTAINER=		packages@netbsd.org

WRKSRC=			${WRKDIR}/psmisc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/killall ${PREFIX}/bin
	${LN} -sf killall ${PREFIX}/bin/pidof
	${INSTALL_PROGRAM} ${WRKSRC}/pstree ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/killall.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/pidof.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/pstree.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
