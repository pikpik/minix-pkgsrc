# $NetBSD$

.include "../../devel/fann/Makefile.common"
PKGNAME=	${PYPKGPREFIX}-fann-${FANNVERSION}


COMMENT=		Fast Artificial Neural Network python interface

#WRKSRC=		work/fann-${FANNVERSION}/python
PYDISTUTILSPKG=		YES
PYSETUPSUBDIR=		python

.include "../../devel/fann/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
