# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 23:10:41 jlam Exp $

BUILDLINK_TREE+=	buddy

.if !defined(BUDDY_BUILDLINK3_MK)
BUDDY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.buddy+=	buddy>=2.4
BUILDLINK_PKGSRCDIR.buddy?=	../../devel/buddy
.endif # BUDDY_BUILDLINK3_MK

BUILDLINK_TREE+=	-buddy
