# $NetBSD: Makefile,v 1.20 2008/06/12 02:14:38 joerg Exp $
#

DISTNAME=	adns-1.4
CATEGORIES=	net
MASTER_SITES=	http://www.chiark.greenend.org.uk/~ian/adns/ftp/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.chiark.greenend.org.uk/~ian/adns/
COMMENT=	Asynchronous-capable DNS client library and utilities
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake
USE_LIBTOOL=		YES

GNU_CONFIGURE=		YES
# libtoolize patch to static library target.
CONFIGURE_ARGS+=	--disable-dynamic

INSTALL_MAKE_FLAGS=	prefix=${DESTDIR}${PREFIX}

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
