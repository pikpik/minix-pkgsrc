# $NetBSD$
#

DISTNAME=	libmpcdec-1.2.4
CATEGORIES=	audio
MASTER_SITES=	http://files.musepack.net/source/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.musepack.net/
COMMENT=	Portable Musepack decoder library

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/mpcdec

.include "../../mk/bsd.pkg.mk"
