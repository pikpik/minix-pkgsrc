# $NetBSD: buildlink3.mk,v 1.10 2006/07/08 23:10:51 jlam Exp $

BUILDLINK_TREE+=	gle

.if !defined(GLE_BUILDLINK3_MK)
GLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gle+=		gle>=3.0.3
BUILDLINK_ABI_DEPENDS.gle+=	gle>=3.1.0nb2
BUILDLINK_PKGSRCDIR.gle?=	../../graphics/gle

.include "../../graphics/Mesa/buildlink3.mk"
.endif # GLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-gle
