# $NetBSD: Makefile,v 1.4 2004/01/20 12:22:21 agc Exp $
#

DISTNAME=	ripe-whois-tools-2.4
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ripe.net/tools/

MAINTAINER=	seb@pbox.org
HOMEPAGE=	http://www.ripe.net/ripencc/pub-services/db/
COMMENT=	RIPE WHOIS client and tools

WRKSRC=		${WRKDIR}

LIBS.NetBSD=	-lcrypt
LIBS.SunOS=	-lnsl -lsocket

MAKE_ENV+=	LIBS="${LIBS}"

.include "../../mk/bsd.pkg.mk"
