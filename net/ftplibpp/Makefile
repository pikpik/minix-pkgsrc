# $NetBSD: Makefile,v 1.6 2006/10/04 21:53:16 wiz Exp $
#

DISTNAME=		ftplibpp-1.0.1
PKGREVISION=		1
CATEGORIES=		net devel
MASTER_SITES=		http://download.berlios.de/kasablanca/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://kasablanca.berlios.de/ftplibpp/
COMMENT=		C++ class providing ftp client functionality

USE_TOOLS+=		gmake

INSTALLATION_DIRS=	include lib share/doc/ftplibpp

post-install:
	${INSTALL_DATA} ${WRKSRC}/ftplibpp.html ${PREFIX}/share/doc/ftplibpp

.include "../../mk/bsd.pkg.mk"
