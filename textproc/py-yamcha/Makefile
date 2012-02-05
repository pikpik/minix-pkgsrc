# $NetBSD: Makefile,v 1.1.1.1 2010/05/19 12:10:10 obache Exp $
#

.include "../../textproc/yamcha/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES+=	python

COMMENT=	YamCha python module

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++

PYSETUPSUBDIR=	python

EGG_NAME=	${DISTNAME:S/-/_python-/}

BUILDLINK_API_DEPENDS.yamcha+=	yamcha>=${PKGVERSION_NOREV}
.include "../../textproc/yamcha/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
