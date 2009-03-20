# $NetBSD: buildlink3.mk,v 1.8 2006/07/08 23:10:37 jlam Exp $

BUILDLINK_TREE+=	tremor

.if !defined(TREMOR_BUILDLINK3_MK)
TREMOR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tremor+=	tremor>=1.0.2
BUILDLINK_ABI_DEPENDS.tremor+=	tremor>=1.0.2nb5
BUILDLINK_PKGSRCDIR.tremor?=	../../audio/tremor
.endif # TREMOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-tremor
