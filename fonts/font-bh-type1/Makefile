# $NetBSD: Makefile,v 1.7 2012/06/12 02:10:23 mef Exp $
#

DISTNAME=		font-bh-type1-1.0.3
CATEGORIES=		fonts
MASTER_SITES=		${MASTER_SITE_XORG:=font/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Standard Bigelow & Holmes TrueType fonts

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		FCCACHE=${TOOLS_CMD.true:Q}

FONTS_DIRS.type1=	share/fonts/X11/Type1
FONTS_DIRS.x11=		share/fonts/X11/Type1

INSTALLATION_DIRS=	share/doc/font-bh-type1

post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/share/doc/font-bh-type1

.include "../../mk/bsd.pkg.mk"
