# $NetBSD: Makefile,v 1.3 2007/02/20 09:01:03 wiz Exp $

PKGNAME=	gnuradio-core-docs-${VERSION}
COMMENT=	GNU Radio core module documentation

.include "../../meta-pkgs/gnuradio/Makefile.common"

USE_TOOLS=	make pkg-config
CONFIGURE_ARGS+=--enable-doxygen

BUILD_DEPENDS+=doxygen>=1.4.7:../../devel/doxygen

do-build:
	cd ${WRKSRC}/gnuradio-core/doc && make

do-install:
	cd ${WRKSRC}/gnuradio-core/doc && make install

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
