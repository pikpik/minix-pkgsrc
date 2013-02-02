# $NetBSD$

BUILDLINK_TREE+=	sfslite

.if !defined(SFSLITE_BUILDLINK3_MK)
SFSLITE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sfslite+=	sfslite>=1.2.7
BUILDLINK_PKGSRCDIR.sfslite?=	../../devel/sfslite

.endif	# SFSLITE_BUILDLINK3_MK

BUILDLINK_TREE+=	-sfslite
