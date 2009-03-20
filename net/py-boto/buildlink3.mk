# $NetBSD: buildlink3.mk,v 1.2 2008/04/25 21:54:15 tnn Exp $

BUILDLINK_TREE+=	py-boto

.if !defined(PY_BOTO_BUILDLINK3_MK)
PY_BOTO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-boto+=	${PYPKGPREFIX}-boto>=1.0a
BUILDLINK_PKGSRCDIR.py-boto?=	../../net/py-boto
.endif # PY_BOTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-boto
