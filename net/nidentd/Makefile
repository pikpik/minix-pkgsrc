# $NetBSD: Makefile,v 1.3 2002/03/29 17:10:02 hubertf Exp $
#

DISTNAME=	nidentd-1.0
CATEGORIES=	net sysutils
MASTER_SITES=	ftp://ftp.arhea.net/pub/NetBSD/nidentd/
EXTRACT_SUFX=	.tgz

MAINTAINER=	hubertf@netbsd.org
COMMENT=	identd that supports IPv4, IPv6, NAT, fake and random

DEPENDS+=	lsof>=4.61:../../sysutils/lsof

do-build:
		${SED} \
			-e 's,@LOCALBASE@,${LOCALBASE},' \
			<${WRKSRC}/nidentd >${WRKSRC}/nidentd.tmp
		${MV} ${WRKSRC}/nidentd.tmp ${WRKSRC}/nidentd

do-install:
		${INSTALL_DATA} ${WRKSRC}/nidentd.nat ${PREFIX}/etc/nidentd.nat.example ; \
		${INSTALL_DATA} ${WRKSRC}/nidentd.fake ${PREFIX}/etc/nidentd.fake.example ; \
		${INSTALL_SCRIPT} ${WRKSRC}/nidentd ${PREFIX}/libexec

.include "../../mk/bsd.pkg.mk"
