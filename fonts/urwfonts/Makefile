# $NetBSD: Makefile,v 1.1 2002/11/07 08:06:36 sjg Exp $
#

DISTNAME=	urw-fonts
PKGNAME=	urwfonts-20021107
CATEGORIES=	fonts
MASTER_SITES=	http://www.gimp.org/

MAINTAINER=	packages@netbsd.org
COMMENT=	URW postscript fonts

NO_PATCH=	# defined
NO_CONFIGURE=	# defined
NO_BUILD=	# defined
WRKSRC=		${WRKDIR}
USE_X11BASE=	yes

X11FONTS=	${PREFIX}/lib/X11/fonts

do-install:
	${INSTALL_DATA_DIR} ${X11FONTS}
	cd ${WRKDIR} && ${PAX} -pe -rw URW ${X11FONTS}

.include "../../mk/bsd.pkg.mk"
