# $NetBSD: Makefile,v 1.1.1.1 2004/08/02 13:13:39 drochner Exp $
#

PKGNAME=	vtk-${VTKDIST_VERSION}

COMMENT=	Visualization toolkit

USE_X11=	yes

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/vtk/Makefile.vtkdist"
.include "../../mk/bsd.pkg.mk"
