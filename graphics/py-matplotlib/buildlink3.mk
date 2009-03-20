# $NetBSD: buildlink3.mk,v 1.4 2009/03/20 17:30:11 joerg Exp $

BUILDLINK_TREE+=	pymatplotlib

.if !defined(PY_MATPLOTLIB_BUILDLINK3_MK)
PY_MATPLOTLIB_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.pymatplotlib+=	${PYPKGPREFIX}-matplotlib>=0.87.2
BUILDLINK_PKGSRCDIR.pymatplotlib?=	../../graphics/py-matplotlib
.endif # PY_MATPLOTLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-pymatplotlib
