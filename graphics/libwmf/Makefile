# $NetBSD: Makefile,v 1.22 2001/05/22 09:32:21 wiz Exp $
#

DISTNAME=		libwmf-0.1.21
CATEGORIES=		graphics devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=wvware/}

MAINTAINER=		kei@netbsd.org
HOMEPAGE=		http://www.wvware.com/libwmf.html
COMMENT=		library for reading and converting WMF (Windows Meta Files)

USE_BUILDLINK_ONLY=	YES
USE_X11=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--includedir="${PREFIX}/include/libwmf"

INCLUDEDIR=		${PREFIX}/include/libwmf
HTMLDIR=		${PREFIX}/share/doc/html/libwmf
WRKSRC=			${WRKDIR}/libwmf

post-extract:
	${CHMOD} a-x ${WRKSRC}/doc/*.html

pre-install:
	${INSTALL_DATA_DIR} ${INCLUDEDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/myxpm.h ${INCLUDEDIR}
	${INSTALL_DATA_DIR} ${HTMLDIR}
	${INSTALL_DATA_DIR} ${HTMLDIR}/pics
	cd ${WRKSRC}; ${INSTALL_DATA} doc/*.html doc/*.gif \
		COPYING CREDITS README ${HTMLDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} doc/pics/weave.jpg \
		${HTMLDIR}/pics

.include "../../graphics/freetype-lib/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
