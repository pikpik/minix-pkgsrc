# $NetBSD: Makefile,v 1.5 2007/03/12 06:46:41 wiz Exp $
#

DISTNAME=		PerceptualDiff-1.0.1
PKGNAME=		pdiff-1.0.1
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pdiff/}

MAINTAINER=		heinz@NetBSD.org
HOMEPAGE=		http://pdiff.sourceforge.net/
COMMENT=		Image comparison through perceptually based image metric

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++

CMAKEFLAGS.pdiff+=	-DCMAKE_INSTALL_PREFIX:PATH=${PREFIX}

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
	  ${LOCALBASE}/bin/cmake ${CMAKEFLAGS.pdiff} .

.include "../../devel/cmake/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
