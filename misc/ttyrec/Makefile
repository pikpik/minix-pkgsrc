# $NetBSD$

DISTNAME=	ttyrec-1.0.4
CATEGORIES=	misc
MASTER_SITES=	http://namazu.org/~satoru/ttyrec/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://namazu.org/~satoru/ttyrec/
COMMENT=	ttyrec is a tty recorder

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} ttyrec ttyplay ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
