# $NetBSD: Makefile,v 1.40 2006/02/15 17:37:08 drochner Exp $

DISTNAME=	Numeric-24.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=numpy/}

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://numeric.scipy.org/
COMMENT=	Adds multidimensional numeric arrays to Python

PYDISTUTILSPKG=	yes
PYBINMODULE=	yes
PYSETUP=	setup.py

.if exists(/System/Library/Frameworks/vecLib.framework)
BUILDLINK_PASSTHRU_DIRS+=	/System/Library/Frameworks/vecLib.framework/Headers
PLIST_SUBST+=	DOTBLAS=""
.else
PLIST_SUBST+=	DOTBLAS="@comment "
.endif

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
