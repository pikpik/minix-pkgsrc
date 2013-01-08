# $NetBSD$

DISTNAME=	Flask-REST-1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/F/Flask-REST/

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/ametaireau/flask-rest/
COMMENT=	Simple REST toolkit for Flask
LICENSE=	modified-bsd

EGG_NAME=	${DISTNAME:S/-/_/}
USE_LANGUAGES=	# empty

DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
