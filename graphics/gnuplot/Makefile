# $NetBSD: Makefile,v 1.28 2004/06/25 17:08:13 adrianp Exp $
#

SVR4_PKGNAME=		gplot
CATEGORIES+=		x11

CONFLICTS+=             gnuplot-nox11-[0-9]*

USE_X11=		YES

.include "../../graphics/gnuplot/Makefile.common"

.include "../../graphics/plotutils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
