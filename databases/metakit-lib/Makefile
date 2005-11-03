# $NetBSD: Makefile,v 1.12 2005/07/29 04:25:18 grant Exp $
#

DISTNAME=	metakit-2.4.9.3
PKGNAME=	metakit-lib-2.4.9.3
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://www.equi4.com/pub/mk/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.equi4.com/metakit/
COMMENT=	Embedded database library

GNU_CONFIGURE=	yes
CONFIGURE_DIRS=	builds
CONFIGURE_SCRIPT= ../unix/configure
CONFIGURE_ARGS+=	--without-tcl
BUILD_DIRS=	builds
USE_LANGUAGES=	c++
USE_LIBTOOL=	yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/include/mk4io.h ${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
