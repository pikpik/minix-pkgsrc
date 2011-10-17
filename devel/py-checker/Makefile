# $NetBSD: Makefile,v 1.14 2008/06/12 02:14:28 joerg Exp $

DISTNAME=	pychecker-0.8.14
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pychecker/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pychecker.sourceforge.net/
COMMENT=	Python code checker
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

PLIST_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX:Q}
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}

EGG_NAME=	PyChecker-${PKGVERSION_NOREV}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
