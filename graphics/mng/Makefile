# $NetBSD$

DISTNAME=	libmng-1.0.0
PKGNAME=	${DISTNAME:S/lib//}
CATEGORIES=	graphics
MASTER_SITES=	http://www.3-t.com/libmng/download/ \
		${MASTER_SITE_SOURCEFORGE:=libmng/} \
		http://www.libmng.com/download/

MAINTAINER=	packages@netbsd.com
HOMEPAGE=	http://www.libmng.com/
COMMENT=	Multiple-image Network Graphics (MNG) reference library

DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	lcms>=1.06:../../graphics/lcms

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

CONFIGURE_ARGS=	--with-jpeg=${PREFIX} \
		--with-lcms=${PREFIX}

.include "../../mk/bsd.pkg.mk"
