# $NetBSD: Makefile,v 1.6 2004/06/25 17:09:27 adrianp Exp $
#

PKGNAME=                ${DISTNAME:C/-/-nox11-/}
SVR4_PKGNAME=		gplot

CONFLICTS+=		gnuplot-[0-9]*

CONFIGURE_ARGS+=	--without-x

.include "../../graphics/gnuplot/Makefile.common"

.include "../../graphics/plotutils-nox11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
