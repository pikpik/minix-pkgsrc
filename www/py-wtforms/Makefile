# $NetBSD: Makefile,v 1.2 2013/01/09 19:02:44 kleink Exp $

DISTNAME=	WTForms-1.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/W/WTForms/
EXTRACT_SUFX=	.zip

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://wtforms.simplecodes.com/
COMMENT=	Flexible forms validation and rendering library
LICENSE=	modified-bsd

USE_LANGUAGES=	# empty

PYTHON_VERSIONS_INCLUDE_3X=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	31

post-extract:
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} -x {} \;

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
