# $NetBSD: Makefile,v 1.4 2001/06/26 13:06:21 zuntum Exp $

DISTNAME=	libogg-1.0rc1
PKGNAME=	libogg-1.0.0.5
CATEGORIES=	devel audio
MASTER_SITES=	http://www.vorbis.com/files/rc1/unix/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.xiph.org/ogg/
COMMENT=	Ogg project codecs library

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

PLIST_SUBST+=		DISTNAME=${DISTNAME}

.include "../../mk/bsd.pkg.mk"
