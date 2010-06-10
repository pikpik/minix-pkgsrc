# $NetBSD: buildlink3.mk,v 1.5 2009/03/20 19:24:44 joerg Exp $

BUILDLINK_TREE+=	pymatplotlib

.if !defined(PYMATPLOTLIB_BUILDLINK3_MK)
PYMATPLOTLIB_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.pymatplotlib+=	${PYPKGPREFIX}-matplotlib>=0.87.2
BUILDLINK_PKGSRCDIR.pymatplotlib?=	../../graphics/py-matplotlib
.endif # PYMATPLOTLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-pymatplotlib
