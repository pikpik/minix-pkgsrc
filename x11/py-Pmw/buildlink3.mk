# $NetBSD: buildlink3.mk,v 1.8 2009/03/20 19:25:48 joerg Exp $

BUILDLINK_TREE+=	py-Pmw

.if !defined(PY_PMW_BUILDLINK3_MK)
PY_PMW_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-Pmw+=	${PYPKGPREFIX}-Pmw-[0-9]*
BUILDLINK_ABI_DEPENDS.py-Pmw?=	${PYPKGPREFIX}-Pmw>=1.2nb1
BUILDLINK_PKGSRCDIR.py-Pmw?=	../../x11/py-Pmw
.endif # PY_PMW_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-Pmw
