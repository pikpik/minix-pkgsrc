# $NetBSD$

BUILDLINK_TREE+=	bullet

.if !defined(BULLET_BUILDLINK3_MK)
BULLET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.bullet+=	bullet>=2.76
BUILDLINK_PKGSRCDIR.bullet?=	../../devel/bullet

#.include "../../graphics/glut/buildlink3.mk"
.endif	# BULLET_BUILDLINK3_MK

BUILDLINK_TREE+=	-bullet
