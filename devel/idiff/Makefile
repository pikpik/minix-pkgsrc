# $NetBSD: Makefile,v 1.19 2001/02/16 14:38:18 wiz Exp $
#

DISTNAME=	idiff-1.0
CATEGORIES=	devel
MASTER_SITES=	http://www.darwinsys.com/freeware/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.darwinsys.com/freeware/
COMMENT=	Interactive front-end to diff(1)

do-install:
	${BSD_INSTALL_PROGRAM} ${WRKSRC}/idiff ${PREFIX}/bin/idiff

.include "../../mk/bsd.pkg.mk"
