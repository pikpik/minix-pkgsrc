# $NetBSD: Makefile,v 1.3 2011/11/17 19:43:11 ryoon Exp $
#

DISTNAME=	libalac-r3
PKGNAME=	alacconvert-0.0.20111026
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://alac.macosforge.org/
COMMENT=	Apple Lossless Audio Codec converter by Apple
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/libalac-r3/convert-utility
USE_LANGUAGES=	c c++
MAKE_FILE=	makefile
BUILD_TARGET=	alacconvert

.include "../../audio/libalac/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
