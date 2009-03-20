# $NetBSD: buildlink3.mk,v 1.7 2006/07/08 23:10:42 jlam Exp $

BUILDLINK_TREE+=	ffcall

.if !defined(FFCALL_BUILDLINK3_MK)
FFCALL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ffcall+=	ffcall>=1.9
BUILDLINK_ABI_DEPENDS.ffcall+=	ffcall>=1.10nb1
BUILDLINK_PKGSRCDIR.ffcall?=	../../devel/ffcall
.endif # FFCALL_BUILDLINK3_MK

BUILDLINK_TREE+=	-ffcall
