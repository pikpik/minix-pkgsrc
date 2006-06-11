# $NetBSD: Makefile,v 1.3 2006/02/17 19:19:13 wiz Exp $
#

DISTNAME=		Cheetah-0.9.18
PKGNAME=		${PYPKGPREFIX}-cheetah-0.9.18
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=cheetahtemplate/}

CONFLICTS=		Cheetah-[0-9]*

MAINTAINER=		shannonjr@NetBSD.org
HOMEPAGE=		http://cheetahtemplate.sourceforge.net/
COMMENT=		Python-powered template engine and code-generator

PYDISTUTILSPKG=		yes
PYBINMODULE=		yes
PYSETUP=		setup.py
PYTHON_VERSIONS_ACCEPTED=	24 23 22

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
