# $NetBSD: Makefile,v 1.2 2005/12/05 20:50:14 rillig Exp $
#

DISTNAME=		freefont-ttf
PKGNAME=		${DISTNAME}-20050407
CATEGORIES=		fonts
MASTER_SITES=		http://savannah.nongnu.org/download/freefont/

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.nongnu.org/freefont/
COMMENT=		Free UCS Outline Fonts: FreeMono, FreeSans, and FreeSerif

DIST_SUBDIR=		${PKGNAME_NOREV}

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}
NO_CONFIGURE=		yes
NO_BUILD=		yes
USE_LANGUAGES=		# empty
INSTALLATION_DIRS=	share/fonts/freefont share/doc/freefont

do-install:
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/freefont/
	${INSTALL_DATA} ${WRKSRC}/AUTHORS \
		${DESTDIR}${PREFIX}/share/doc/freefont/
	${INSTALL_DATA} ${WRKSRC}/CREDITS \
		${DESTDIR}${PREFIX}/share/doc/freefont/
	cd ${WRKSRC}/sfd && \
		${PAX} -rw Free*.ttf ${DESTDIR}${PREFIX}/share/fonts/freefont/

.include "../../mk/bsd.pkg.mk"
