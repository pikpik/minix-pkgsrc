# $NetBSD: Makefile,v 1.3 2010/07/23 23:17:48 gdt Exp $
#

VERSION=	0.5.25
DISTNAME=	pycryptopp-${VERSION}
PKGNAME=	${PYPKGPREFIX}-cryptopp-${VERSION}
CATEGORIES=	security python
MASTER_SITES=	http://pypi.python.org/packages/source/p/pycryptopp/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tahoe-lafs.org/trac/pycryptopp
COMMENT=	Python wrapper for (and copy of parts of) crypto++

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
