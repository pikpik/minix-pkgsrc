# $NetBSD: Makefile,v 1.2 2006/03/04 21:29:47 jlam Exp $
#

DISTNAME=		exifprobe-2.0.1
CATEGORIES=		graphics
MASTER_SITES=		http://www.virtual-cafe.com/~dhh/tools.d/exifprobe.d/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE= http://www.virtual-cafe.com/~dhh/tools.d/exifprobe.d/exifprobe.html
COMMENT=		EXIF data extractor

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALL_MAKE_FLAGS+=	BINDIR=${DESTDIR}${PREFIX}/bin \
			MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
