# $NetBSD: Makefile,v 1.5 2004/12/03 15:14:59 wiz Exp $
#

DISTNAME=	wideangle
PKGNAME=	gimp2-wideangle-1.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.ozemail.com.au/~hodsond/
EXTRACT_SUFX=	.c

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.ozemail.com.au/~hodsond/wideangle.html
COMMENT=	GIMP plugin for wideangle lens distortions

DIST_SUBDIR=	${PKGNAME}
WRKSRC=         ${WRKDIR}
USE_BUILDLINK3=	YES
EXTRACT_CMD=    ${CP} ${DOWNLOADED_DISTFILE} ${WRKSRC}

do-build:
	(cd ${WRKSRC} && gimptool-2.0 --build wideangle.c)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wideangle \
		${PREFIX}/lib/gimp/2.0/plug-ins

.include "../../graphics/gimp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
