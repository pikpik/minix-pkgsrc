# $NetBSD: Makefile,v 1.10 2012/10/23 17:19:09 asau Exp $
#

DISTNAME=		socket++-1.12.10
PKGREVISION=		2
CATEGORIES=		net
MASTER_SITES=		http://www.linuxhacker.at/linux/downloads/src/

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		http://www.linuxhacker.at/socketxx/
COMMENT=		C++ class library for UNIX Sockets with exception handling

INFO_FILES=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
USE_TOOLS+=		automake gmake makeinfo
TEST_DIRS=		test
TEST_TARGET=		check

pre-configure:
		cd ${WRKSRC};						\
		${LOCALBASE}/bin/libtoolize --automake;                 \
		aclocal -I .;						\
		autoheader;						\
		automake --add-missing;					\
		autoconf

.include "../../mk/bsd.pkg.mk"
