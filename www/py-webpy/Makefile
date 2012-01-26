# $NetBSD: Makefile,v 1.8 2011/11/29 18:16:56 darcy Exp $
#

DISTNAME=		web.py-0.36
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		www python
MASTER_SITES=	http://webpy.org/static/

MAINTAINER=		darcy@NetBSD.org
HOMEPAGE=		http://webpy.org/
COMMENT=		Simple, public domain web publishing system
LICENSE=		public-domain

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		#none

PYTHON_VERSIONS_ACCEPTED=	27 26 25

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
