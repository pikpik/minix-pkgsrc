# $NetBSD: Makefile,v 1.5 2003/12/04 13:50:33 adam Exp $
#

DISTNAME=	rpy-0.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=rpy/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=       http://rpy.sourceforge.net/
COMMENT=	R interface for Python

USE_BUILDLINK3=		YES
PYDISTUTILSPKG=		YES

.include "../../lang/python/extension.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../math/R/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
