# $NetBSD: buildlink3.mk,v 1.7 2006/07/08 23:11:11 jlam Exp $

BUILDLINK_TREE+=	libunicode

.if !defined(LIBUNICODE_BUILDLINK3_MK)
LIBUNICODE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libunicode+=		libunicode>=0.4
BUILDLINK_ABI_DEPENDS.libunicode+=	libunicode>=0.4nb1
BUILDLINK_PKGSRCDIR.libunicode?=	../../textproc/libunicode
.endif # LIBUNICODE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libunicode
