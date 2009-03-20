# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 23:10:45 jlam Exp $

BUILDLINK_TREE+=	liboop

.if !defined(LIBOOP_BUILDLINK3_MK)
LIBOOP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liboop+=	liboop>=0.9
BUILDLINK_ABI_DEPENDS.liboop+=	liboop>=1.0nb1
BUILDLINK_PKGSRCDIR.liboop?=	../../devel/liboop
.endif # LIBOOP_BUILDLINK3_MK

BUILDLINK_TREE+=	-liboop
