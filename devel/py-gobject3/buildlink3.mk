# $NetBSD$

BUILDLINK_TREE+=	py-gobject3

.if !defined(PY_GOBJECT3_BUILDLINK3_MK)
PY_GOBJECT3_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-gobject3+=	${PYPKGPREFIX}-gobject3>=3.2.2
BUILDLINK_PKGSRCDIR.py-gobject3?=	../../devel/py-gobject3

.endif	# PY_GOBJECT3_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-gobject3
