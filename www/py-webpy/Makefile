# $NetBSD: Makefile,v 1.7 2011/06/14 09:06:07 obache Exp $
#

DISTNAME=		web.py-0.36
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		www python
MASTER_SITES=	http://webpy.org/static/

MAINTAINER=		darcy@NetBSD.org
HOMEPAGE=		http://webpy.org/
COMMENT=		Simple, public domain web publishing system
LICENSE=		public-domain

PKG_DESTDIR_SUPPORT=	user-destdir
PYTHON_VERSIONS_ACCEPTED=   27 26 25

PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
