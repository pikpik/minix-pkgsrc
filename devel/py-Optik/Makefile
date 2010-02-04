# $NetBSD: Makefile,v 1.13 2008/06/12 02:14:28 joerg Exp $

DISTNAME=	optik-1.5.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/optik/Optik/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=optik/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://optik.sourceforge.net/
COMMENT=	Command line parsing library for Python
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} test/test_optik.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
