# $NetBSD: Makefile,v 1.1.1.1 2001/03/15 20:35:58 wiz Exp $

DISTNAME=	libao-0.6.0
PKGNAME=	${DISTNAME}nb1
CATEGORIES=	devel
MASTER_SITES=	http://www.vorbis.com/files/beta4/unix/

MAINTAINER=	reed@reedmedia.net
COMMENT=	cross-platform audio library

BUILD_DEPENDS+=	${LOCALBASE}/bin/automake:../../devel/automake
BUILD_DEPENDS+=	${LOCALBASE}/bin/autoconf:../../devel/autoconf

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
