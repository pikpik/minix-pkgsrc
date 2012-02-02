# $NetBSD: Makefile,v 1.7 2008/11/09 22:48:59 bjs Exp $
#

DISTNAME=		terminus-font-4.36
CATEGORIES=		fonts
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=terminus-font/}

MAINTAINER=		j+pkgsrc@salmi.ch
HOMEPAGE=		http://terminus-font.sourceforge.net/
COMMENT=		Clean, fixed-width font
LICENSE=		open-font-license

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		bdftopcf gmake gzip perl

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--x11dir=${PREFIX}/lib/X11/fonts/misc

BUILD_TARGET=		pcf
INSTALL_TARGET=		install-pcf

FONTS_DIRS.x11=		${PREFIX}/lib/X11/fonts/misc
REQD_DIRS+=		${PREFIX}/lib/X11/fonts/misc

.include "../../mk/bsd.pkg.mk"
