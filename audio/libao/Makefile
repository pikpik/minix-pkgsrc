# $NetBSD$

DISTNAME=	libao-0.6.0
CATEGORIES=	devel
MASTER_SITES=	http://www.vorbis.com/files/beta4/unix/

MAINTAINER=	reed@reedmedia.net
COMMENT=	cross-platform audio library

DEPENDS+=	esound>=0.2.8:../../audio/esound

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/src/ltconfig

.include "../../mk/bsd.pkg.mk"
