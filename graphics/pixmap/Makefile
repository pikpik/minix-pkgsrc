# $NetBSD: Makefile,v 1.10 2000/08/23 23:14:27 tron Exp $
# FreeBSD: Makefile,v 1.8 1996/11/18 09:53:36 asami Exp
#

DISTNAME=		pixmap2.6
PKGNAME=		pixmap-2.6pl4
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=applications/pixmap/}
PATCH_SITES=		${MASTER_SITES}
PATCHFILES=		pixmap_2.6.patch1.gz \
			pixmap_2.6.patch2.gz \
			pixmap_2.6.patch3.gz \
			pixmap_2.6.patch4.gz

MAINTAINER=		packages@netbsd.org

BUILD_DEPENDS+=		rman:../../textproc/rman

USE_IMAKE=		YES
USE_XPM=		YES

WRKSRC=			${WRKDIR}/pixmap

.include "../../mk/bsd.pkg.mk"
