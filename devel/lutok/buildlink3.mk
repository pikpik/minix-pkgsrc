# $NetBSD$

BUILDLINK_TREE+=	lutok

.if !defined(LUTOK_BUILDLINK3_MK)
LUTOK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lutok+=	lutok>=0.1
BUILDLINK_PKGSRCDIR.lutok?=	../../devel/lutok

.include "../../lang/lua/buildlink3.mk"
.endif	# LUTOK_BUILDLINK3_MK

BUILDLINK_TREE+=	-lutok
