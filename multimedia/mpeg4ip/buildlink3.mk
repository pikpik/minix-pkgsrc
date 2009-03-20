# $NetBSD: buildlink3.mk,v 1.3 2006/07/08 23:11:02 jlam Exp $

BUILDLINK_TREE+=	mpeg4ip

.if !defined(MPEG4IP_BUILDLINK3_MK)
MPEG4IP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mpeg4ip+=	mpeg4ip>=1.4.1
BUILDLINK_PKGSRCDIR.mpeg4ip?=	../../multimedia/mpeg4ip
.endif # MPEG4IP_BUILDLINK3_MK

BUILDLINK_TREE+=	-mpeg4ip
