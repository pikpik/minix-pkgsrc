# $NetBSD: Makefile,v 1.14 2010/04/23 21:43:28 wiz Exp $

DISTNAME=	libogg-1.2.1
CATEGORIES=	multimedia devel
MASTER_SITES=	http://downloads.xiph.org/releases/ogg/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.xiph.org/ogg/
COMMENT=	Ogg project codecs library
LICENSE=	modified-bsd

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

GCC_REQD+=	2.95.3

PKGCONFIG_OVERRIDE+=	ogg.pc.in

TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
