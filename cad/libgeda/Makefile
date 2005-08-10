# $NetBSD: Makefile,v 1.34 2005/07/21 16:29:44 wiz Exp $
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
USE_TOOLS+=		pkg-config

INFO_FILES=		libgedadoc.info

.include "../../graphics/libgdgeda/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
