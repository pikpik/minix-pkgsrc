# $NetBSD: Makefile,v 1.17 2012/04/08 19:09:09 wiz Exp $

DISTNAME=	IPy-0.75
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/IPy/IP/}
CATEGORIES=	net python
MASTER_SITES=	http://pypi.python.org/packages/source/I/IPy/

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	https://github.com/haypo/python-ipy/
COMMENT=	Python module to handle IPv4 and IPv6 address
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCLUDE_3X=	yes

do-test:
	${RUN}cd ${WRKSRC}/test; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test_IPy.py

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
