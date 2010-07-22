# $NetBSD: Makefile,v 1.25 2010/01/17 12:02:43 wiz Exp $
#

DISTNAME=	pycryptopp-0.5.19
PKGNAME=	${PYPKGPREFIX}-cryptopp-0.5.19
CATEGORIES=	security python
MASTER_SITES=	http://pypi.python.org/packages/source/p/pycryptopp/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tahoe-lafs.org/trac/pycryptopp
COMMENT=	Python wrapper for crypto++

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../security/crypto++/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
