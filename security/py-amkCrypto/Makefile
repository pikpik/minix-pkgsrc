# $NetBSD: Makefile,v 1.17 2005/04/11 21:47:18 tv Exp $
#

DISTNAME=	pycrypto-2.0.1
PKGNAME=	${PYPKGPREFIX}-amkCrypto-2.0.1
CATEGORIES=	security python
MASTER_SITES=	http://www.amk.ca/files/python/crypto/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.amk.ca/python/code/crypto.html
COMMENT=	Cryptographic and hash functions for Python

PYBINMODULE=	yes
PYDISTUTILSPKG=	yes

.include "../../security/openssl/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
