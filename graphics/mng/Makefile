# $NetBSD: Makefile,v 1.1.1.1 2001/03/07 08:34:52 skrll Exp $

DISTNAME=	libmng-1.0.0
PKGNAME=	${DISTNAME:S/lib//}
CATEGORIES=	graphics
MASTER_SITES=	http://www.3-t.com/libmng/download/ \
		${MASTER_SITE_SOURCEFORGE:=libmng/} \
		http://www.libmng.com/download/

MAINTAINER=	packages@netbsd.com
HOMEPAGE=	http://www.libmng.com/
COMMENT=	Multiple-image Network Graphics (MNG) reference library

USE_BUILDLINK_ONLY=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

CONFIGURE_ARGS+=	--with-jpeg=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-lcms=${BUILDLINK_DIR}

.include "../../devel/zlib/buildlink.mk"
.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/lcms/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
