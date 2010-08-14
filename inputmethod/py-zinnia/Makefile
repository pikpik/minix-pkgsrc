# $NetBSD: Makefile,v 1.1.1.1 2010/05/20 09:07:34 obache Exp $
#

.include "../../inputmethod/zinnia/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES+=	python

COMMENT=	Zinnia python module

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PYSETUPSUBDIR=	python

EGG_NAME=	zinnia_python-0.0.0

BUILDLINK_API_DEPENDS.zinnia+=	zinnia>=${PKGVERSION_NOREV}
.include "../../inputmethod/zinnia/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
