# $NetBSD: Makefile,v 1.7 1999/03/09 16:43:07 agc Exp $
#

DISTNAME=	arpwatch-2.1a4
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ee.lbl.gov/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	bouyer@netbsd.org

GNU_CONFIGURE=	yes

post-install:
	${INSTALL_MAN} ${WRKSRC}/arpwatch.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/arpsnmp.8 ${PREFIX}/man/man8
	@/bin/test -e /var/db/arpwatch || ${MKDIR} /var/db/arpwatch
	${TOUCH} /var/db/arpwatch/arp.dat
	${INSTALL_DATA} ${WRKSRC}/ethercodes.dat ${PREFIX}/etc

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
DEPENDS+=	libpcap-0.4:../../net/libpcap
.endif

.include "../../mk/bsd.pkg.mk"
