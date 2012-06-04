# $NetBSD: Makefile,v 1.8 2012/04/22 21:15:21 wiz Exp $
#

DISTNAME=	beautifulsoup4-4.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://www.crummy.com/software/BeautifulSoup/bs4/download/4.0/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.crummy.com/software/BeautifulSoup/
COMMENT=	HTML/XML Parser for Python, version 4
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml

PKG_DESTDIR_SUPPORT=		user-destdir
PYTHON_VERSIONS_INCLUDE_3X=	yes

do-test:
	cd ${WRKSRC} &&  ${PYTHONBIN} -m unittest discover -s bs4

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
