# $NetBSD$

DISTNAME=		esound-0.2.4
CATEGORIES=		audio
MASTER_SITES=		ftp://ftp.enlightenment.org/pub/enlightenment/enlightenment/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://pw1.netcom.com/~ericmit/EsounD.html

WRKSRC=			${WRKDIR}/esound
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

post-install:
	${RM} ${LOCALBASE}/lib/libesd.la

.include "../../mk/bsd.pkg.mk"
