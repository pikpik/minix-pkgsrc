# $NetBSD: Makefile,v 1.3 2003/07/21 17:10:43 martti Exp $
#

DISTNAME=	gopher_3.0.6
PKGNAME=	${DISTNAME:S/_/-/}
WRKSRC=		${WRKDIR}/gopher
CATEGORIES=	net
MASTER_SITES=	http://gopher.quux.org:70/give-me-gopher/

MAINTAINER=	jgoerzen@complete.org
HOMEPAGE=	gopher://quux.org/1/devel/gopher/
COMMENT=	Distributed document delivery client and server

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
CONFIGURE_ARGS+= --disable-auth

.include "../../mk/bsd.pkg.mk"
