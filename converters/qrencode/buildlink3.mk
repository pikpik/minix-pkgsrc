# $NetBSD: buildlink3.mk,v 1.1 2008/06/15 10:33:38 gavan Exp $

BUILDLINK_TREE+=	qrencode

.if !defined(QRENCODE_BUILDLINK3_MK)
QRENCODE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qrencode+=	qrencode>=3.0.3
BUILDLINK_PKGSRCDIR.qrencode?=	../../converters/qrencode
.endif # QRENCODE_BUILDLINK3_MK

BUILDLINK_TREE+=	-qrencode
