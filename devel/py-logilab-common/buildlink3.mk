# $NetBSD$

BUILDLINK_TREE+=	py-llab-common

.if !defined(PY_LOGILAB_COMMON_BUILDLINK3_MK)
PY_LOGILAB_COMMON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-llab-common+= ${PYPKGPREFIX}-logilab-common>=0.53.0
BUILDLINK_PKGSRCDIR.py-llab-common?=	../../devel/py-logilab-common

.endif	# PY_LOGILAB_COMMON_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-llab-common
