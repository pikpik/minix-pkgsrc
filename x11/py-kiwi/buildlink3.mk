# $NetBSD: buildlink3.mk,v 1.2 2009/03/06 18:13:58 jmcneill Exp $

BUILDLINK_TREE+=	py-kiwi

.if !defined(PY_KIWI_BUILDLINK3_MK)
PY_KIWI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-kiwi+=	${PYPKGPREFIX}-kiwi>=1.9.22
BUILDLINK_PKGSRCDIR.py-kiwi?=	../../x11/py-kiwi

.include "../../x11/py-gtk2/buildlink3.mk"
.endif # PY_KIWI_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-kiwi
