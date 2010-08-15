# $NetBSD$

BUILDLINK_TREE+=	rope

.if !defined(ROPE_BUILDLINK3_MK)
ROPE_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.rope+=	${PYPKGPREFIX}-rope>=0.9.2
BUILDLINK_PKGSRCDIR.rope?=	../../devel/py-rope
.endif	# ROPE_BUILDLINK3_MK

BUILDLINK_TREE+=	-rope
