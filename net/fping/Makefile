# $NetBSD: Makefile,v 1.6 2002/02/18 18:40:41 abs Exp $
# FreeBSD Id: ports/net/fping/Makefile,v 1.10 2000/04/20 20:18:57 mharo Exp

DISTNAME=	fping-2.4b2_to
PKGNAME=	fping-2.4b2
CATEGORIES=	net
MASTER_SITES=	http://www.fping.com/download/

MAINTAINER=	abs@netbsd.org
HOMEPAGE=	http://www.fping.com/
COMMENT=	Quickly ping many hosts w/o flooding the network

GNU_CONFIGURE=	YES

post-install:
	${CHMOD} 4555 ${LOCALBASE}/sbin/fping

.include "../../mk/bsd.pkg.mk"
