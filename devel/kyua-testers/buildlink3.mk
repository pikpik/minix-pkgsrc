# $NetBSD$

BUILDLINK_TREE+=	kyua-testers

.if !defined(KYUA_TESTERS_BUILDLINK3_MK)
KYUA_TESTERS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kyua-testers+=	kyua-testers>=0.1
BUILDLINK_PKGSRCDIR.kyua-testers?=	../../devel/kyua-testers
.endif	# KYUA_TESTERS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kyua-testers
