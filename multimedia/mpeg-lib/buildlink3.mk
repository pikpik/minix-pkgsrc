# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 23:11:02 jlam Exp $

BUILDLINK_TREE+=	mpeg

.if !defined(MPEG_BUILDLINK3_MK)
MPEG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mpeg+=	mpeg>=1.3.1
BUILDLINK_ABI_DEPENDS.mpeg+=	mpeg>=1.3.1nb1
BUILDLINK_PKGSRCDIR.mpeg?=	../../multimedia/mpeg-lib
.endif # MPEG_BUILDLINK3_MK

BUILDLINK_TREE+=	-mpeg
