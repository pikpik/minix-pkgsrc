# $NetBSD: Makefile,v 1.2 1999/09/15 03:33:59 kim Exp $
#

DISTNAME=	netname-1.7
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=	kim@tac.nyc.ny.us

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
ALL_TARGET=	svr4
.else
ALL_TARGET=	netbsd
.endif
INSTALL_TARGET=	inst-all

.include "../../mk/bsd.pkg.mk"
