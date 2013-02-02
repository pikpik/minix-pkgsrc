# $NetBSD$

BUILDLINK_TREE+=	py-cython

.if !defined(PY_CYTHON_BUILDLINK3_MK)
PY_CYTHON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-cython+=	${PYPKGPREFIX}-cython>=0.12.1
BUILDLINK_PKGSRCDIR.py-cython?=	../../devel/py-cython
.endif	# PY_CYTHON_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-cython
