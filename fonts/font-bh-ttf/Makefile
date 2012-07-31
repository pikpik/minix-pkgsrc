# $NetBSD: Makefile,v 1.7 2012/06/12 02:10:23 mef Exp $
#

DISTNAME=		font-bh-ttf-1.0.3
PKGREVISION=		1
CATEGORIES=		fonts
MASTER_SITES=		${MASTER_SITE_XORG:=font/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Standard Bigelow & Holmes TrueType fonts

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes

FONTS_DIRS.ttf=		share/fonts/X11/TTF
FONTS_DIRS.x11=		share/fonts/X11/TTF

INSTALLATION_DIRS=	share/doc/font-bh-ttf

PKG_SYSCONFSUBDIR=	fontconfig
CONF_FILES=	${PREFIX}/share/fontconfig/conf.avail/42-luxi-mono.conf \
		${PKG_SYSCONFDIR}/conf.d/42-luxi-mono.conf

post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/share/doc/font-bh-ttf

.include "../../mk/bsd.pkg.mk"
