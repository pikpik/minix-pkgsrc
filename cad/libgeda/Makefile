# $NetBSD: Makefile,v 1.31 2004/10/15 14:50:06 tv Exp $
#

DISTNAME=		libgeda-${PKGVERSION}
CATEGORIES=		cad

MAINTAINER=		dmcmahill@NetBSD.org
HOMEPAGE=		http://www.geda.seul.org/
COMMENT=		Library of shared modules for gEDA

CONFLICTS+=		gEDA<19991011

.include "../../cad/geda/Makefile.common"

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_BUILDLINK3=		YES

INFO_FILES=		libgedadoc.info

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../graphics/libgdgeda/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
