# $NetBSD: Makefile,v 1.9 1999/11/03 23:50:08 hubertf Exp $
#

.include 	"Makefile.common"

MAINTAINER=     hubertf@netbsd.org
HOMEPAGE=       http://hive.me.gu.edu.au/not_lame/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lame ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/doc/man/lame.1 ${PREFIX}/man/man1/lame.1

.include "../../mk/bsd.pkg.mk"
