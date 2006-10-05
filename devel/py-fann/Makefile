# $NetBSD: Makefile,v 1.1.1.1 2006/10/05 14:56:23 gdt Exp $

.include "../../devel/fann/Makefile.common"
PKGNAME=	${PYPKGPREFIX}-fann-${FANNVERSION}

COMMENT=		Fast Artificial Neural Network python interface

PYDISTUTILSPKG=		YES
PYSETUPSUBDIR=		python

.include "../../devel/fann/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
