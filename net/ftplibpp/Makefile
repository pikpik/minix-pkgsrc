# $NetBSD: Makefile,v 1.5 2006/03/04 21:30:18 jlam Exp $
#

DISTNAME=		ftplibpp-1.0.1
PKGREVISION=		1
CATEGORIES=		net devel
MASTER_SITES=		http://download.berlios.de/kasablanca/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://kasablanca.berlios.de/ftplibpp/
COMMENT=		C++ class providing ftp client functionality

USE_TOOLS+=		gmake

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ftplibpp
	${INSTALL_DATA} ${WRKSRC}/ftplibpp.html ${PREFIX}/share/doc/ftplibpp

.include "../../mk/bsd.pkg.mk"
