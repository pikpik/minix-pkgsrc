# $NetBSD: Makefile,v 1.1.1.1 2004/04/21 20:46:54 drochner Exp $
#

DISTNAME=	numarray-1.0
PKGNAME=	${PYPKGPREFIX}-numarray-1.0
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=numpy/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.stsci.edu/resources/software_hardware/numarray
COMMENT=	Array manipulation

USE_BUILDLINK3=		yes
PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_ACCEPTED= 23pth 22pth

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
