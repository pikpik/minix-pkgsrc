# $NetBSD: Makefile,v 1.11 2002/05/18 17:47:59 dmcmahill Exp $
#

DISTNAME=	gwave-20020122
CATEGORIES=	cad
MASTER_SITES=	http://www.cs.unc.edu/~tell/dist/

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://www.cs.unc.edu/~tell/gwave/
COMMENT=	viewer for spice-like simulator output and other analog data

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

.include "../../devel/guile-gtk/buildlink2.mk"
.include "../../graphics/plotutils/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
