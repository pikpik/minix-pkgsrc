# $NetBSD: buildlink3.mk,v 1.9 2006/07/08 23:10:36 jlam Exp $

BUILDLINK_TREE+=	lame

.if !defined(LAME_BUILDLINK3_MK)
LAME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lame+=	lame>=3.93.1nb2
BUILDLINK_ABI_DEPENDS.lame+=	lame>=3.96.1nb4
BUILDLINK_PKGSRCDIR.lame?=	../../audio/lame
.endif # LAME_BUILDLINK3_MK

BUILDLINK_TREE+=	-lame
