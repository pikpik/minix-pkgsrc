# $NetBSD: Makefile,v 1.17 2002/03/13 17:36:44 fredb Exp $
#

DISTNAME=	psiconv-0.8.2
PKGREVISION=	2
CATEGORIES=	converters
MASTER_SITES=	http://huizen.dds.nl/~frodol/psiconv/

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://huizen.dds.nl/~frodol/psiconv/
COMMENT=	PSION 5 file format data conversion utilities

USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
USE_X11=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
GNU_CONFIGURE=		YES
CPPFLAGS+=		-DIMAGEMAGICK

DOCDIR=		${PREFIX}/share/doc/psiconv

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}/docs; for file in ascii html html4; do		\
		${INSTALL_DATA} $${file} ${DOCDIR};			\
	done

.include "../../graphics/ImageMagick/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
