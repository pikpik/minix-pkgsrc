# $NetBSD: Makefile,v 1.1.1.1 2001/07/01 16:43:59 itojun Exp $

DISTNAME=	bridged-20010701
WRKSRC=		${WRKDIR}/bridged
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.kame.net/pub/kame/misc/

MAINTAINER=	packages@netbsd.org
COMMENT=	userland ethernet bridge daemon

GNU_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bridge ${PREFIX}/sbin/bridged

.include "../../mk/bsd.pkg.mk"
