# $NetBSD: Makefile,v 1.6 2002/07/11 14:24:00 abs Exp $
#

.include "Makefile.common"

PKGNAME=	lib${DISTNAME}
PKGREVISION=	4
COMMENT=	open source Flash(tm) library

USE_BUILDLINK2=	yes
USE_LIBTOOL=	yes
BUILD_DIRS=	${WRKSRC}/Lib
MAKE_ENV+=	LIBOSSAUDIO="${LIBOSSAUDIO}"

.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
