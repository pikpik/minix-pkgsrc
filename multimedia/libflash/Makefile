# $NetBSD: Makefile,v 1.1.1.1 2004/01/26 13:34:45 jmmv Exp $
#

.include "Makefile.common"

PKGNAME=	lib${DISTNAME}
PKGREVISION=	4
COMMENT=	Open source Flash(tm) library

USE_BUILDLINK3=	yes
USE_LIBTOOL=	yes
BUILD_DIRS=	${WRKSRC}/Lib
MAKE_ENV+=	LIBOSSAUDIO="${LIBOSSAUDIO}"
MAKE_ENV+=	LIBSTDCPP=-lstdc++

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
