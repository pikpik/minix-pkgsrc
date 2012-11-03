# $NetBSD$

BUILDLINK_TREE+=	py-irclib

.if !defined(PY_IRCLIB_BUILDLINK3_MK)
PY_IRCLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-irclib+=	${PYPKGPREFIX}-irclib>=3.4.2
BUILDLINK_PKGSRCDIR.py-irclib?=	../../net/py-irclib

.endif	# PY_IRCLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-irclib
