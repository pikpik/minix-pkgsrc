# $NetBSD: Makefile,v 1.7 2001/02/16 14:39:07 wiz Exp $

DISTNAME=	zlib-1.1.3
CATEGORIES=	devel
MASTER_SITES=   ftp://ftp.freesoftware.com/pub/infozip/zlib/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	ftp://ftp.freesoftware.com/pub/infozip/zlib/index.html
COMMENT=	General purpose data compression library

BUILD_DEPENDS+=	libtool-base>=${LIBTOOL_VERSION}:../../devel/libtool-base

ONLY_FOR_PLATFORM=	SunOS-*-* # in base NetBSD system

LIBTOOL=	${LOCALBASE}/bin/libtool
CONFIGURE_ENV+=	LIBTOOL="${LIBTOOL} ${LIBTOOL_FLAGS}"
MAKE_ENV+=	LIBTOOL="${LIBTOOL} ${LIBTOOL_FLAGS}"
MAKEFILE=	lt.mk

post-extract:
	${CP} ${FILESDIR}/lt.mk ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
