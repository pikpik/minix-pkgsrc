# $NetBSD: Makefile,v 1.10 2008/06/12 02:14:42 joerg Exp $
#

PKGNAME=		${PYPKGPREFIX}-twisted-${TWISTED_VERSION}
COMMENT=		Framework for writing networked applications
.include "../../net/py-twisted/Makefile.common"

DEPENDS+=		${PYPKGPREFIX}-OpenSSL>=0.7:../../security/py-OpenSSL
DEPENDS+=		${PYPKGPREFIX}-ZopeInterface>=3.0.1:../../devel/py-ZopeInterface

PYDISTUTILSPKG=		yes

do-test:
	cd ${WRKSRC} && ./build/scripts-${PYVERSSUFFIX}/trial twisted

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
