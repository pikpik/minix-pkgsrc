# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/11/13 15:55:55 wulf Exp $

BUILDLINK_TREE+=	py-ephem

.if !defined(PY_EPHEM_BUILDLINK3_MK)
PY_EPHEM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-ephem+=	${PYPKGPREFIX}-ephem>=3.7b
BUILDLINK_PKGSRCDIR.py-ephem?=	../../math/py-ephem
.endif # PY_EPHEM_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-ephem
