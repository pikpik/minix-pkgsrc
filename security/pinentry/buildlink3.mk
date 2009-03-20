# $NetBSD: buildlink3.mk,v 1.7 2006/07/08 23:11:08 jlam Exp $

BUILDLINK_TREE+=	pinentry

.if !defined(PINENTRY_BUILDLINK3_MK)
PINENTRY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pinentry+=	pinentry>=0.7.1
BUILDLINK_ABI_DEPENDS.pinentry+=	pinentry>=0.7.1nb3
BUILDLINK_PKGSRCDIR.pinentry?=	../../security/pinentry
.endif # PINENTRY_BUILDLINK3_MK

BUILDLINK_TREE+=	-pinentry
