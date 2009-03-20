# $NetBSD: buildlink3.mk,v 1.7 2006/07/08 23:11:00 jlam Exp $

BUILDLINK_TREE+=	proj

.if !defined(PROJ_BUILDLINK3_MK)
PROJ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.proj+=	proj>=4.4.7nb1
BUILDLINK_ABI_DEPENDS.proj?=	proj>=4.4.7nb2
BUILDLINK_PKGSRCDIR.proj?=	../../misc/proj
.endif # PROJ_BUILDLINK3_MK

BUILDLINK_TREE+=	-proj
