# $NetBSD: Makefile,v 1.10 1998/04/22 14:22:43 agc Exp $

DISTNAME=	tiff-v3.4beta037
PKGNAME=	tiff-3.4
CATEGORIES=	graphics
MASTER_SITES=   ftp://ftp.sgi.com/graphics/tiff/ \
		ftp://ftp.gwdg.de/pub/grafik/sgi/tiff/ \
		ftp://ftp.fu-berlin.de/unix/graphics/tiff/
EXTRACT_SUFX=	-tar.gz

MAINTAINER=	tron@netbsd.org

DEPENDS+=	jpeg-6a:../../graphics/jpeg

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--noninteractive --site ${FILESDIR}
CONFIGURE_ENV+=		PREFIX=${PREFIX}

post-install:
	${LDCONFIG} || ${TRUE}

.include "../../mk/bsd.pkg.mk"
