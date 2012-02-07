# $NetBSD: Makefile,v 1.1.1.1 2011/10/16 05:33:56 manu Exp $
#

DISTNAME=	libmemcached-1.0.4
CATEGORIES=	devel
MASTER_SITES=	http://launchpad.net/libmemcached/1.0/${PKGVERSION}/+download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libmemcached.org/
COMMENT=	C/C++ client library and tools for the memcached server
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	support/libmemcached.pc.in

# Avoid building 64bit on a 32bit bootstrap (affects SunOS)
.if empty(ABI:M64)
CONFIGURE_ARGS+=	--disable-64bit
.endif

.include "../../mk/bsd.pkg.mk"
