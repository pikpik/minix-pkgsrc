# $NetBSD: Makefile,v 1.1.1.1 2010/09/09 02:15:22 joerg Exp $
#

DISTNAME=		openjpeg-1.5.0
CATEGORIES=		graphics
MASTER_SITES=		http://openjpeg.googlecode.com/files/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.openjpeg.org/
COMMENT=		JPEG 2000 library

PKG_DESTDIR_SUPPORT=	user-destdir
LICENSE=		2-clause-bsd

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-doc
USE_LIBTOOL=		yes

CFLAGS+=	-DHAVE_POSIX_MEMALIGN

.include "../../mk/bsd.pkg.mk"
