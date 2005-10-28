# $NetBSD: Makefile,v 1.1.1.1 2005/10/14 00:32:53 minskim Exp $
#

DISTNAME=		rxvt-unicode-5.8
CATEGORIES=		x11
MASTER_SITES=		http://dist.schmorp.de/rxvt-unicode/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		lems@gmx.net
HOMEPAGE=		http://software.schmorp.de/#rxvt-unicode
COMMENT=		rxvt clone supporting Xft fonts and Unicode

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c++
USE_TOOLS+=		gmake pkg-config

CONFIGURE_ARGS+=	--enable-transparency	\
			--enable-menubar		\
			--enable-xpm-background	\
			--enable-xgetdefault		\
			--with-term=rxvt	\
			--enable-24bit

.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
