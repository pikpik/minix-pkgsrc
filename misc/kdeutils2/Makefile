# $NetBSD$
#

DISTNAME=	kdeutils-2.1
CATEGORIES=	misc kde
.include "../../x11/kde2/Makefile.part1"
COMMENT=	Utilities for the KDE integrated X11 desktop

DEPENDS+=	kdebase-2.1:../../x11/kdebase2

.include "../../x11/kde2/Makefile.part2"

CONFIGURE_ENV+=	LIBS="-Wl,--export-dynamic"

.include "../../mk/bsd.pkg.mk"
