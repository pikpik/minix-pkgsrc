# $NetBSD: Makefile,v 1.2 2002/03/05 23:29:08 skrll Exp $
#

DISTNAME=		flac-1.0.2-src
PKGNAME=		flac-1.0.2
WRKSRC=			${WRKDIR}/${PKGNAME}
CATEGORIES=		audio archivers
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=flac/}

MAINTAINER=		collver@linuxfreemail.com
HOMEPAGE=		http://flac.sourceforge.net
COMMENT=		free lossless audio codec

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_PLATFORM:MNetBSD-*-i386} != ""
BUILD_DEPENDS+=		nasm>=0.98:../../devel/nasm
.endif

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/flac
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/flac/images
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/flac/ru
	${INSTALL_DATA} ${WRKSRC}/doc/images/*.gif \
		${WRKSRC}/doc/images/*.jpg \
		${PREFIX}/share/doc/flac/images
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${PREFIX}/share/doc/flac
	${INSTALL_DATA} ${WRKSRC}/doc/ru/*.html ${PREFIX}/share/doc/flac/ru

.include "../../audio/libogg/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
