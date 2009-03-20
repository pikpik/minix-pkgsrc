# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 23:11:00 jlam Exp $

BUILDLINK_TREE+=	yorick

.if !defined(YORICK_BUILDLINK3_MK)
YORICK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.yorick+=	yorick>=1.5.12
BUILDLINK_DEPMETHOD.yorick?=	build
BUILDLINK_ABI_DEPENDS.yorick?=	yorick>=1.6.02nb1
BUILDLINK_PKGSRCDIR.yorick?=	../../math/yorick
.endif # YORICK_BUILDLINK3_MK

BUILDLINK_TREE+=	-yorick
