# $NetBSD: buildlink3.mk,v 1.7 2006/07/08 23:10:42 jlam Exp $

BUILDLINK_TREE+=	edcommon

.if !defined(EDCOMMON_BUILDLINK3_MK)
EDCOMMON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.edcommon+=	edcommon>=32
BUILDLINK_ABI_DEPENDS.edcommon?=	edcommon>=32nb2
BUILDLINK_PKGSRCDIR.edcommon?=	../../devel/edcommon
.endif # EDCOMMON_BUILDLINK3_MK

BUILDLINK_TREE+=	-edcommon
