# $NetBSD: buildlink3.mk,v 1.3 2009/03/05 21:03:35 joerg Exp $

BUILDLINK_TREE+=	xtrans

.if !defined(XTRANS_BUILDLINK3_MK)
XTRANS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xtrans?=		xtrans>=1.0.3
BUILDLINK_PKGSRCDIR.xtrans?=		../../x11/xtrans
BUILDLINK_DEPMETHOD.xtrans?=		build
.endif # XTRANS_BUILDLINK3_MK

BUILDLINK_TREE+=	-xtrans
