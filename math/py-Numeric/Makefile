# $NetBSD: Makefile,v 1.22 2001/07/11 10:32:00 drochner Exp $

DISTNAME=	Numeric-20.2.1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=numpy/}

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.pfdubois.com/numpy/
COMMENT=	Adds multidimensional numeric arrays to Python

PYTHON_VERSIONS_ACCEPTED=	21 20
PYDISTUTILSPKG=	yes
PYBINMODULE=	yes
PYSETUP=	setup_all.py

.include "../../lang/python/extension.buildlink.mk"
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
.include "../../mk/bsd.pkg.mk"
