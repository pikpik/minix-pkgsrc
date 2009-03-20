# $NetBSD: buildlink3.mk,v 1.7 2006/07/08 23:11:03 jlam Exp $

BUILDLINK_TREE+=	hesiod

.if !defined(HESIOD_BUILDLINK3_MK)
HESIOD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hesiod+=	hesiod>=3.0.2
BUILDLINK_PKGSRCDIR.hesiod?=	../../net/hesiod
BUILDLINK_DEPMETHOD.hesiod?=	build
.endif # HESIOD_BUILDLINK3_MK

BUILDLINK_TREE+=	-hesiod
