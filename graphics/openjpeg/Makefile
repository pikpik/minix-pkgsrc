# $NetBSD: Makefile,v 1.2 2012/03/24 13:25:00 drochner Exp $
#

DISTNAME=		openjpeg-1.5.0
PKGREVISION=		1
CATEGORIES=		graphics
MASTER_SITES=		http://openjpeg.googlecode.com/files/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.openjpeg.org/
COMMENT=		JPEG 2000 library
LICENSE=		2-clause-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-doc
USE_LIBTOOL=		yes

CFLAGS+=	-DHAVE_POSIX_MEMALIGN

.include "../../mk/bsd.pkg.mk"
