# $NetBSD: Makefile,v 1.19 2010/01/17 12:02:43 wiz Exp $
#

DISTNAME=	pyOpenSSL-0.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	security python
MASTER_SITES=	http://pypi.python.org/packages/source/p/pyOpenSSL/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pyopenssl.sourceforge.net/
COMMENT=	Python interface to the OpenSSL library

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
