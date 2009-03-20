# $NetBSD: buildlink3.mk,v 1.7 2006/07/08 23:11:10 jlam Exp $

BUILDLINK_TREE+=	kakasi

.if !defined(KAKASI_BUILDLINK3_MK)
KAKASI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kakasi+=	kakasi>=2.3.0
BUILDLINK_ABI_DEPENDS.kakasi+=	kakasi>=2.3.4nb4
BUILDLINK_PKGSRCDIR.kakasi?=	../../textproc/kakasi
.endif # KAKASI_BUILDLINK3_MK

BUILDLINK_TREE+=	-kakasi
