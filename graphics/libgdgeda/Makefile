# $NetBSD: Makefile,v 1.16 2003/11/03 10:51:46 agc Exp $
#

DISTNAME=		libgdgeda-2.0.15
PKGREVISION=		1
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.geda.seul.org/pub/geda/devel/support/

MAINTAINER=		dmcmahill@NetBSD.org
HOMEPAGE=		http://www.geda.seul.org/
COMMENT=		Modified version of the gd packages for use with gEDA

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DIST_SUBDIR=		${PKGNAME}

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_BUILDLINK3=		YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
