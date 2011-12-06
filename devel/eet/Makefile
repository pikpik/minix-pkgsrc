# $NetBSD: Makefile,v 1.19 2010/12/23 11:44:26 dsainty Exp $
#

DISTNAME=	eet-1.5.0
CATEGORIES=	devel archivers
MASTER_SITES=	http://download.enlightenment.org/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.enlightenment.org/
COMMENT=	Library for speedy storage, retrieval, and compression

LICENSE=	2-clause-bsd

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

PKGCONFIG_OVERRIDE=	eet.pc.in

INSTALLATION_DIRS=	share/doc/eet

post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYING ${WRKSRC}/AUTHORS \
	    ${DESTDIR}${PREFIX}/share/doc/eet

.include "../../devel/eina/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
