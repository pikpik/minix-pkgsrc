# $NetBSD: Makefile,v 1.1.1.1 1999/06/28 01:34:22 hubertf Exp $
#

DISTNAME=	ngrep-1.31
CATEGORIES=	net
MASTER_SITES=	http://www.packetfactory.net/ngrep/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.packetfactory.net/ngrep/

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/ngrep
ALL_TARGET=	ngrep

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
DEPENDS+=	libpcap-0.4:../../net/libpcap

do-configure:
	cd ${WRKSRC}; ./configure --prefix=${PREFIX}
.endif

.include "../../mk/bsd.pkg.mk"
