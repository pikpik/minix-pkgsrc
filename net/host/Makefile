# $NetBSD: Makefile,v 1.8 2004/01/20 12:22:19 agc Exp $

DISTNAME=	host-20040812
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.weird.com/pub/local/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.weird.com/~woods/projects/host.html
COMMENT=	A powerful DNS query and testing tool

.include "../../mk/bsd.prefs.mk"

NO_CONFIGURE =	yes
NO_PATCH =	yes

MAKEFILE=	Makefile.BSD

MAKE_FLAGS+=	__NetBSD__=1

.include "../../mk/bsd.pkg.mk"
