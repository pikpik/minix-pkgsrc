# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:24:58 joerg Exp $

BUILDLINK_TREE+=	pycython

.if !defined(PY_CYTHON_BUILDLINK3_MK)
PY_CYTHON_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.pycython+= ${PYPKGPREFIX}-cython>=0.12.1
BUILDLINK_PKGSRCDIR.pycython?=	../../devel/py-cython

.endif # PY_CYTHON_BUILDLINK3_MK

BUILDLINK_TREE+=	-pycython
