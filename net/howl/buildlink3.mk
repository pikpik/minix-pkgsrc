# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 23:11:03 jlam Exp $

BUILDLINK_TREE+=	howl

.if !defined(HOWL_BUILDLINK3_MK)
HOWL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.howl+=	howl>=0.9.5
BUILDLINK_ABI_DEPENDS.howl+=	howl>=0.9.5nb1
BUILDLINK_PKGSRCDIR.howl?=	../../net/howl
.endif # HOWL_BUILDLINK3_MK

BUILDLINK_TREE+=	-howl
