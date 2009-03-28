# $NetBSD$

BUILDLINK_TREE+=	synce-rra

.if !defined(SYNCE_RRA_BUILDLINK3_MK)
SYNCE_RRA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.synce-rra+=	synce-rra>=0.9.1nb2
BUILDLINK_PKGSRCDIR.synce-rra?=	../../comms/synce-rra

.include "../../comms/synce-librapi2/buildlink3.mk"
.include "../../comms/synce-libsynce/buildlink3.mk"
.include "../../devel/libmimedir/buildlink3.mk"
.endif	# SYNCE_RRA_BUILDLINK3_MK

BUILDLINK_TREE+=	-synce-rra
