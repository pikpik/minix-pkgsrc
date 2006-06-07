# $NetBSD: Makefile,v 1.6 2006/02/20 23:16:00 wiz Exp $
#

DISTNAME=	Gnosis_Utils-1.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
PKGREVISION=	4
CATEGORIES=	textproc python
MASTER_SITES=	http://gnosis.cx/download/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://gnosis.cx/download/
COMMENT=	Classes for working with XML

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes
PYTHON_VERSIONS_ACCEPTED=	24 23 22

.include "../../lang/python/extension.mk"
.include "../../textproc/py-xml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
