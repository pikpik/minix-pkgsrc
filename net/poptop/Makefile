# $NetBSD: Makefile,v 1.3 2001/02/17 18:19:27 wiz Exp $

DISTNAME=	pptpd-1.0.1
PKGNAME=	poptop-1.0.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.snapgear.com/poptop/

MAINTAINER=	dbj@netbsd.org
HOMEPAGE=	http://www.snapgear.com/vpn/pptp.html
COMMENT=	PPTP server which can support Microsoft VPN clients

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-libwrap

.include "../../mk/bsd.prefs.mk"

.if defined(POPTOP_USE_MPPE)
DEPENDS+=	ppp-mppe-2.3.9:../../net/ppp-mppe
CONFIGURE_ARGS+= --with-pppd=${PREFIX}/sbin/pppd
.endif

post-patch:
	${TOUCH} ${WRKSRC}/config.h.in

.include "../../mk/bsd.pkg.mk"
