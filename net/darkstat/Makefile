# $NetBSD: Makefile,v 1.3 2006/10/07 07:49:01 obache Exp $
#

DISTNAME=		darkstat-3.0.619
CATEGORIES=		net
MASTER_SITES=		http://dmr.ath.cx/net/darkstat/
DIST_SUBDIR=		darkstat
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		http://dmr.ath.cx/net/darkstat/
COMMENT=		Network statistics gatherer

BUILD_TARGET=		darkstat

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-chroot-dir=${PREFIX}/share/darkstat/chroot

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/darkstat
	${INSTALL_DATA_DIR} ${PREFIX}/share/darkstat/chroot

.include "../../devel/zlib/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
