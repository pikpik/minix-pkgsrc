# $NetBSD: buildlink2.mk,v 1.1 2002/10/24 22:24:24 drochner Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pyfoursuite
BUILDLINK_DEPENDS.pyfoursuite?=	${PYPKGPREFIX}-FourSuite-*
BUILDLINK_PKGSRCDIR.pyfoursuite?=	../../textproc/py-FourSuite
