# $NetBSD$

BUILDLINK_TREE+=	kdemultimedia4

.if !defined(KDEMULTIMEDIA4_BUILDLINK3_MK)
KDEMULTIMEDIA4_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdemultimedia4+=	kdemultimedia4>=4.1.0
BUILDLINK_PKGSRCDIR.kdemultimedia4?=	../../multimedia/kdemultimedia4

.endif # KDEMULTIMEDIA4_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdemultimedia4
