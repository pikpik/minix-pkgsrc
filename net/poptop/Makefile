# $NetBSD$

DISTNAME=	pptpd-1.0.0
PKGNAME=	poptop-1.0.0
CATEGORIES=	net
MASTER_SITES=	http://www.moretonbay.com/vpn/releases/
EXTRACT_SUFX=   .tgz

MAINTAINER=	dbj@netbsd.org
HOMEPAGE=	http://www.moretonbay.com/vpn/pptp.html

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-libwrap

.include "../../mk/bsd.prefs.mk"

.if defined(POPTOP_USE_MPPE)
RUN_DEPENDS+=	${PREFIX}/sbin/pppd:../ppp-mppe
CONFIGURE_ARGS+= --with-pppd=${PREFIX}/sbin/pppd
.endif

post-patch:
	${TOUCH} ${WRKSRC}/config.h.in

.include "../../mk/bsd.pkg.mk"
