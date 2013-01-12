# $NetBSD: Makefile,v 1.1 2013/01/03 14:04:46 ryoon Exp $
#

DISTNAME=	bleach-1.1.5
PKGREVISION=	1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	http://pypi.python.org/packages/source/b/bleach/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://pypi.python.org/pypi/bleach
COMMENT=	Easy whitelist-based HTML-sanitizing tool
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-html5lib-[0-9]*:../../textproc/py-html5lib

USE_LANGUAGES=	# none

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
