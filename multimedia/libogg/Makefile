# $NetBSD: Makefile,v 1.5 2005/07/21 16:29:54 wiz Exp $
#

DISTNAME=	libogg-1.1.2
PKGREVISION=	1
CATEGORIES=	multimedia devel
MASTER_SITES=	http://downloads.xiph.org/releases/ogg/

MAINTAINER=	lukem@NetBSD.org
HOMEPAGE=	http://www.xiph.org/ogg/
COMMENT=	Ogg project codecs library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

GCC_REQD+=	2.95.3

PLIST_SUBST+=	DISTNAME=${DISTNAME}

PKGCONFIG_OVERRIDE+=	ogg.pc.in

TEST_TARGET=	check


.include "../../mk/bsd.pkg.mk"
