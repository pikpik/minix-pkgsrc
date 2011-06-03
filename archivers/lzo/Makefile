# $NetBSD: Makefile,v 1.10 2010/11/13 11:21:05 obache Exp $

DISTNAME=	lzo-2.05
CATEGORIES=	archivers
MASTER_SITES=	http://ftp.uni-koeln.de/util/arc/ \
		http://www.oberhumer.com/opensource/lzo/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.oberhumer.com/opensource/lzo/
COMMENT=	Portable lossless data compression library
LICENSE=	gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
TEST_TARGET=		test

.include "../../mk/bsd.pkg.mk"
