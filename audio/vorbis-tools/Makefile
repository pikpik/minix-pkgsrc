# $NetBSD: Makefile,v 1.2 2001/04/05 13:18:52 wiz Exp $

DISTNAME=	vorbis-tools-1.0rc1
PKGNAME=	vorbis-tools-1.0.0.5
CATEGORIES=	audio
MASTER_SITES=	http://www.vorbis.com/files/rc1/unix/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.vorbis.com/
COMMENT=	Ogg Vorbis encoder and player

CONFLICTS=	vorbis-*

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CONFIGURE_ARGS+=	--with-ogg-prefix=${PREFIX} \
			--with-vorbis-prefix=${PREFIX} \
			--with-ao-prefix=${PREFIX}

.include "../../audio/libao/buildlink.mk"
.include "../../audio/libogg/buildlink.mk"
.include "../../audio/libvorbis/buildlink.mk"

.include "../../mk/bsd.pkg.mk"
