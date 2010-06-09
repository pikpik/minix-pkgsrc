# $NetBSD: Makefile,v 1.25 2010/02/15 16:32:20 joerg Exp $
#

DISTNAME=	rpy2-2.1.3
PKGNAME=	${PYPKGPREFIX}-rpy-2.1.3
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rpy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rpy.sourceforge.net/
COMMENT=	R interface for Python

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=		YES
USE_LANGUAGES+=		c fortran

BUILDLINK_API_DEPENDS.R+= R>=2.11.0

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../math/R/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
