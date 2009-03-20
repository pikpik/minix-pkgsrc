# $NetBSD: buildlink3.mk,v 1.5 2006/07/08 23:10:49 jlam Exp $

BUILDLINK_TREE+=	lrmi

.if !defined(LRMI_BUILDLINK3_MK)
LRMI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lrmi+=	lrmi>=0.8nb1
BUILDLINK_PKGSRCDIR.lrmi?=	../../emulators/lrmi
.endif # LRMI_BUILDLINK3_MK

BUILDLINK_TREE+=	-lrmi
