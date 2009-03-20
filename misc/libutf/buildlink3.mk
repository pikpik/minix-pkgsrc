# $NetBSD: buildlink3.mk,v 1.7 2006/07/08 23:11:00 jlam Exp $

BUILDLINK_TREE+=	libutf

.if !defined(LIBUTF_BUILDLINK3_MK)
LIBUTF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libutf+=	libutf>=3.0
BUILDLINK_PKGSRCDIR.libutf?=	../../misc/libutf
.endif # LIBUTF_BUILDLINK3_MK

BUILDLINK_TREE+=	-libutf
